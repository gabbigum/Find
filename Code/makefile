CC=gcc

all: compilelib main.o link

compilelib:searchfile.c searchfile.h
	$(CC) -c searchfile.c

main.o:find.c
	$(CC) -c find.c
link:
	$(CC) -o find find.c searchfile.c

clean:
	rm *.o
	rm find