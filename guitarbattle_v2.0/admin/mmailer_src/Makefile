all: mmailer

clean:
	rm *.o mmailer

mmailer.o: mmailer.c
	gcc -Wall -g -c mmailer.c

io.o: io.c

	gcc -Wall -g -c io.c

mmailer: mmailer.o io.o
	gcc -Wall -g -o mmailer mmailer.o io.o
