#ifndef IO_H
#define IO_H

#define CHUNKSIZE 4096

struct connection {
	int fd;
	int flags;

	int readbytes;
	int curbyte;

	char *curline;
	int linemalloc;
	int linesize;

	int error;

	char c_ip[25];

	char chunk[CHUNKSIZE];

};

struct connection *new_connection(int fd);
void free_connection(struct connection *con);
void con_blocking(struct connection *con);
void con_nonblocking(struct connection *con);
char *readline(struct connection *con);
void writeline(struct connection *con, const char *line);
int readresp(struct connection *con);


#endif
