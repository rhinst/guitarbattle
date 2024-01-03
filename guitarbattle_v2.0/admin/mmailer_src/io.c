#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "io.h"

struct connection *new_connection(int fd)
{
	struct connection *con = (struct connection *) malloc(sizeof(struct connection));

	con->fd = fd;
	con->flags = fcntl(fd, F_GETFL);

	memset(con->chunk, 0, CHUNKSIZE);
	memset(con->c_ip, '\0', sizeof(con->c_ip));
	con->readbytes = 0;
	con->curbyte = 0;
	con->curline = (char *) malloc(80);
	con->linemalloc = 80;
	con->linesize = 0;

	con->error = 0;

	return con;
}

void free_connection(struct connection *con)
{
	if (con)
	{
		close(con->fd);
		if (con->curline)
		{
			free(con->curline);
		}
	}
	free(con);
}

void con_blocking(struct connection *con)
{
	if (con->flags & O_NONBLOCK)
	{
		con->flags = con->flags ^ O_NONBLOCK;
		fcntl(con->fd, F_SETFL, con->flags);
	}
}

void con_nonblocking(struct connection *con)
{
	if (!(con->flags & O_NONBLOCK))
	{
		con->flags = con->flags | O_NONBLOCK;
		fcntl(con->fd, F_SETFL, con->flags);
	}
}

char *readline(struct connection *con)
{
	fd_set sockfd;
	struct timeval tv;
	char *tempcl;

	int ret;

	int done = 0;

	con->error = 0;

	con_nonblocking(con);
	con->linesize = 0;

	do
	{
		while (!done && (con->curbyte < con->readbytes))
		{
			if (con->linemalloc == con->linesize)
			{
				con->linemalloc *= 2;
				tempcl = (char *) malloc(con->linemalloc);
				strncpy(tempcl, con->curline, con->linesize);
				free(con->curline);
				con->curline = tempcl;
			}
			if (con->chunk[con->curbyte] == '\r')
			{
				con->curline[con->linesize++] = '\0';
				if (con->chunk[con->curbyte + 1] == '\n')
				{
					con->curbyte++;
				}
				done = 1;
			}
			else if (con->chunk[con->curbyte] == '\n')
			{
				con->curline[con->linesize++] = '\0';
				done = 1;
			}
			else
			{
				con->curline[con->linesize++] = con->chunk[con->curbyte];
			}
			con->curbyte++;
		}

		if (!done)
		{
			FD_ZERO(&sockfd);
			FD_SET(con->fd, &sockfd);

			tv.tv_sec = 300;	// make icmail.cf, also do selectfor main
			tv.tv_usec = 0;

			errno = 0;
			while ((ret = select(con->fd + 1, &sockfd, NULL, NULL, &tv)) != 1)
			{
				if (ret == 0)
				{
					con->error = 1;
					return NULL;
				}
				else if (ret == -1)
				{
					if (errno != EINTR)
					{
						con->error = 1;
						return NULL;
					}
				}
				else
				{	/* shouldnt get here */
					con->error = 1;
					return NULL;
				}
			}


			errno = 0;
			con->readbytes = read(con->fd, con->chunk, CHUNKSIZE);
			if (con->readbytes == -1 || con->readbytes == 0)
			{
				con->error = 1;
				return NULL;
			}
			if (con->readbytes < 0)
			{
			}
			con->chunk[con->readbytes] = '\0';
			con->curbyte = 0;
		}
	}
	while (!done);

	printf("< %s\n", con->curline);

	return con->curline;
}

int readresp(struct connection *con)
{
	int code;
	char *s;
	char c;

	con->error = 0;
	s = readline(con);

	if (s)
	{
		if (isdigit((int) (con->curline[0])) && isdigit((int) (con->curline[1])) && isdigit((int) (con->curline[2])))
		{
			c = con->curline[3];
			con->curline[3] = '\0';
			code = atoi(con->curline);
			con->curline[3] = c;
			while (c == '-')
			{
				s = readline(con);
				c = con->curline[3];
			}
			return code;
		}
	}
	return -1;
	con->error = 1;
	return code;
}

void writeline(struct connection *con, const char *line)
{
	int l = strlen(line);
	char *s = (char *) malloc(l + 3);

	strcpy(s, line);
	s[l] = '\r';
	s[l + 1] = '\n';
	s[l + 2] = '\0';

	con_blocking(con);
	write(con->fd, s, strlen(s));
	printf("> %s", s);

	free(s);
}
