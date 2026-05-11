CC = gcc
CFLAGS = -lm 

mioprogramma: main.o sort.o
	$(CC) main.o sort.o $(CFLAGS) sort

debug:
	$(CC) main.c sort.c -DDEBUG $(CFLAGS) sort
clean: 
	rm -rf *.o
	rm sort
