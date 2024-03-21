CC = gcc
CFLAGS = -Wall -Wextra

all: main clean

main: main.o queue.o
	$(CC) $(CFLAGS) -o main main.o queue.o

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c -o queue.o queue.c

clean:
	rm -f main.o queue.o