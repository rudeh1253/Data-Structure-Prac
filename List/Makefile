CC=gcc
CFLAGS=-o
OBJS=execution.o DoublyLinkedList.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $@ $(OBJS) 

execution.o: LinkedList.h execution.c
DoublyLinkedList.o: LinkedList.h DoublyLinkedList.c