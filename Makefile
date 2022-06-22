CC=gcc
CFLAGS=-Wall -Wextra
BINARIES=put

put: main.c
	$(CC) $(CFLAGS) main.c -o $(BINARIES) 

clean:
	rm -rf $(BINARIES) *.o
