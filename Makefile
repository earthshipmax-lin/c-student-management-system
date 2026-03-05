CC = gcc
CFLAGS = -Wall

TARGET = main

OBJS = main.o list.o file.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

file.o: file.c
	$(CC) $(CFLAGS) -c file.c

clean:
	rm -f *.o $(TARGET)