CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

main: main.o string_utils.o
	$(CC) -o main main.o string_utils.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

string_utils.o: string_utils.c
	$(CC) $(CFLAGS) -c string_utils.c

clean:
	rm -f *.o main
