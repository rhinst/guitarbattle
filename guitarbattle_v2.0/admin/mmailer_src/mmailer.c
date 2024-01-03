#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "io.h"

extern int errno;

#define MAXHOSTNAMELEN	64

void util_replace_str(const char *exp, const char *rep, char *s);
void usage(void);
char *send_message(const char *server, const char *myhost, const char *from, const char *to, const char *msg);

#define FFLUSH() { \
	fflush(stdout);\
}

#define OUT(args...) { \
	if (usestdout) {\
		printf(##args); \
	} else {\
		fprintf(outf, ##args); \
	} \
}

int main(int argc, char **argv) {
	FILE *rf;
	int mfd;

	FILE *outf = NULL;
	int usestdout = 0;
	char outfn[1024];

	char host[MAXHOSTNAMELEN];
	char mid[MAXHOSTNAMELEN + 100];
	int count = 0;
	int okcount = 0;
	char *ret;

	char *from;
	char *fromname;
	char *tolist;
	char *mfile;

	char *mtext = NULL;
	char *mttemp;
	int textmalloc;
	char mtemp[1024];
	int bytes;
	char *msgbuf;

	char recipient[1024];
	char *name;

	if (argc != 5 && argc != 6) {
		usage();
		exit(1);
	}

	if (!strcmp(argv[1], "-s")) {
		if (argc != 6) {
			usage();
			exit(1);
		}
		usestdout = 1;
		from = strdup(argv[2]);
		fromname = strdup(argv[3]);
		tolist = strdup(argv[4]);
		mfile = strdup(argv[5]);
	} else {
		if (argc != 5) {
			usage();
			exit(1);
		}
		from = strdup(argv[1]);
		fromname = strdup(argv[2]);
		tolist = strdup(argv[3]);
		mfile = strdup(argv[4]);
	}

	gethostname(host, sizeof(host));

	errno = 0;
	if ((mfd = open(mfile, O_RDONLY)) == -1) {
		printf("open(%s): %s", mfile, strerror(errno));
		exit(3);
	}
	if (lseek(mfd, 0, SEEK_SET)) {
		printf("lseek(): %s", strerror(errno));
		exit(4);
	}
	errno = 0;

	textmalloc = 1;
	mtext = (char *) malloc(textmalloc);
	mtext[0] = '\0';

	while ((bytes = read(mfd, mtemp, sizeof(mtemp))) > 0) {
		mttemp = (char *) malloc(bytes + textmalloc);
		memcpy(mttemp, mtext, textmalloc);
		memcpy(mttemp + textmalloc - 1, mtemp, bytes);
		mttemp[textmalloc + bytes] = '\0';
		free(mtext);
		mtext = mttemp;
		textmalloc += bytes;	
	}
	if (bytes == -1) {
		printf("read(): %s", strerror(errno));
		exit(5);
	}
	close(mfd);

	if (!(rf = fopen(tolist, "r"))) {
		printf("fopen(%s): %s", tolist, strerror(errno));
		exit(6);
	}

	if (!usestdout) {
		snprintf(outfn, sizeof(outfn), "/tmp/mmailer.%d.out", getpid());
		outf = fopen(outfn, "w");
		if (!outf) {
			perror(argv[0]);
			exit(2);
		}

		close(0);
		close(1);
		close(2);

		if (!fork()) {
			exit(0);
		}
	}

	while (fgets(recipient, sizeof(recipient), rf)) {
		recipient[strlen(recipient) - 1] = '\0';

		name = strchr(recipient, ':');
		if (name) {
			*name++ = '\0';
		} else {
			name = recipient + strlen(recipient);
		}
		OUT("Send to %s (%s) ... ", name, recipient);
		FFLUSH();

		snprintf(mid, sizeof(mid), "<MMAILER.%d.%d.%d@%s>", ++count, getpid(), (int) time(NULL), host);
		msgbuf = (char *) malloc(strlen(from) + strlen(fromname) + strlen(mid) + strlen(mtext) + strlen(recipient) + strlen(name) + 1000);
		sprintf(msgbuf, "Message-ID: %s\nFrom: %s <%s>\n%s\n", mid, fromname, from, mtext);
		util_replace_str("%email%", recipient, msgbuf);
		util_replace_str("%name%", name, msgbuf);

		if ((ret = send_message("127.0.0.1", host, from, recipient, msgbuf))) {
			OUT("%s\n", ret);
			free(ret);
		} else {
			OUT("OK\n");
			okcount++;
		}

		free(msgbuf);
	}

	OUT("Sent %d of %d messages.\n", okcount, count);

	if (!usestdout) {
		fclose(outf);
		errno = 0;
		if ((mfd = open(outfn, O_RDONLY)) == -1) {
			exit(7);
		}

		textmalloc = 1;
		mtext = (char *) malloc(textmalloc);
		memset(mtext, '\0', sizeof(mtext));
		mtext[0] = '\0';


		//printf("Reading message.");
		while ((bytes = read(mfd, mtemp, sizeof(mtemp))) > 0) {
			mttemp = (char *) malloc(bytes + textmalloc);
			memcpy(mttemp, mtext, textmalloc);
			memcpy(mttemp + textmalloc - 1, mtemp, bytes);
			mttemp[textmalloc + bytes] = '\0';
			free(mtext);
			mtext = mttemp;
			textmalloc += bytes;	
		}
		close(mfd);

		//printf("Read:\n%s\n[EOF]\n", mtext);

		snprintf(mid, sizeof(mid), "<MMAILER.%d.%d.%d@%s>", ++count, getpid(), (int) time(NULL), host);
		msgbuf = (char *) malloc(strlen(from) + strlen(fromname) + strlen(mid) + strlen(mtext) + strlen(recipient) + strlen(name) + 10000);
		sprintf(msgbuf, "Message-ID: %s\nFrom: %s <%s>\nTo: %s <%s>\nSubject: Results of Mailing\n%s\n", mid, fromname, from, fromname, from, mtext);
		//printf("Sending message to %s:\n%s\n[EOF]\n", from, msgbuf);

		ret = send_message("127.0.0.1", host, from, from, msgbuf);
		if (ret) {
			printf("ret: %s\n", ret);
			free(ret);
		} else {
			printf("OK\n");
		}

		unlink(outfn);
	}

	exit(0);
}

char *send_message(const char *server, const char *myhost, const char *from, const char *to, const char *msg) {
	int sock, r;
	struct sockaddr_in sin;
	char buf[1024];

	struct connection *con;
	char *error;

	memset((char *) &sin, 0, sizeof(sin));
	sin.sin_addr.s_addr = inet_addr(server);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(25);

	errno = 0;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		error = strerror(errno);
		return strdup(error);
	}
	errno = 0;
	if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) == -1)
	{
		error = strerror(errno);
		close(sock);
		return strdup(error);
	}

	con = new_connection(sock);
	if ((r = readresp(con)) != 220)	/* will read multiline response */
	{
		error = con->curline;
		writeline(con, "QUIT");
		error = strdup(error);
		free_connection(con);
		return error;
	}

	snprintf(buf, sizeof(buf), "HELO %s", myhost);
	writeline(con, buf);
	if ((r = readresp(con)) != 250)
	{
		error = con->curline;
		writeline(con, "QUIT");
		error = strdup(error);
		free_connection(con);
		return error;
	}

	snprintf(buf, sizeof(buf), "MAIL FROM: <%s>", from);
	writeline(con, buf);
	if ((r = readresp(con)) != 250)
	{
		error = con->curline;
		writeline(con, "QUIT");
		error = strdup(error);
		free_connection(con);
		return error;
	}

	snprintf(buf, sizeof(buf), "RCPT TO: <%s>", to);
	writeline(con, buf);
	if ((r = readresp(con)) != 250)
	{
		error = con->curline;
		writeline(con, "QUIT");
		error = strdup(error);
		free_connection(con);
		return error;
	}
	snprintf(buf, sizeof(buf), "DATA");
	writeline(con, buf);
	if ((r = readresp(con)) != 354)
	{
		error = con->curline;
		error = strdup(error);
		writeline(con, "QUIT");
		free_connection(con);
		return error;
	}

	con_blocking(con);
	write(con->fd, msg, strlen(msg));

	writeline(con, ".");
	if ((r = readresp(con)) != 250)
	{
		error = con->curline;
		writeline(con, "QUIT");
		error = strdup(error);
		free_connection(con);
		return error;
	}

	writeline(con, "QUIT");
	free_connection(con);
	return 0;
}

void usage(void) {
	fprintf(stderr, "mmailer from fromname tolist mfile\n");
}

void util_replace_str(const char *exp, const char *rep, char *s) {
	int i, l, m, n, o;
        
	char *newval;

	l = strlen(s);
	m = strlen(exp);
	o = strlen(rep);

	if (o) 
	{
		newval = (char *) malloc((l + 1) * o);
		memset(newval, 0, (l + 1) * o);
	}
	else 
	{
		newval = (char *) malloc((l + 1));
		memset(newval, 0, (l + 1));
	}

	for (i = 0, n = 0; i < l; i++, n++)
	{
		if (s[i] == exp[0] && !strncmp(&s[i], exp, m))
		{
			strcat(newval, rep);
			n += o - 1;
			i += m - 1;
		}
		else
		{
			newval[n] = s[i];
		}
	}

        newval[n] = '\0';

	strcpy(s, newval);
	free(newval);
}
