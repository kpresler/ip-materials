CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra

# Links together files needed to create executable
run_concat: run_concat.o string_functions.o
	$(CC) -o run_concat run_concat.o string_functions.o

# Compiles run_concat.c to create run_concat.o
# Note that we list string_functions.h here as a file that
# run_concat.c depends on, since run_concat.c #includes it
run_concat.o: run_concat.c string_functions.h
	$(CC) $(CFLAGS) -c run_concat.c

# Compiles string_functions.c to create string_functions.o
# Note that we list string_functions.h here as a file that
# string_functions.c depends on, since string_functions.c #includes it
string_functions.o: string_functions.c string_functions.h
	$(CC) $(CFLAGS) -c string_functions.c

# Removes all object files and the executable named run_concat,
# so we can start fresh
clean:
	rm -f *.o run_concat *~
