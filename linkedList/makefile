CC = gcc
CFLAGS = -Wall -Wextra

all: main_program clean

main_program: main.o list.o
	$(CC) $(CFLAGS) -o main_program main.o list.o

main.o: main.c list.h
	$(CC) $(CFLAGS) -c -o main.o main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c -o list.o list.c

clean:
	rm -rf *.o
