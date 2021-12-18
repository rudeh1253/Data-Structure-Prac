CC=gcc
OBJFLAGS=-c -o
OBJS=execution1.o LinkedListSet.o DoublyLinkedList.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CC) -g $(OBJS)

execution1.o: Set/LinkedListSet.h Set/execution1.c
	$(CC) $(OBJFLAGS) $@ Set/execution1.c

LinkedListSet.o: Set/LinkedList.h Set/LinkedListSet.h Set/LinkedListSet.c
	$(CC) $(OBJFLAGS) $@ Set/LinkedListSet.c

DoublyLinkedList.o: Set/LinkedList.h Set/DoublyLinkedList.c
	$(CC) $(OBJFLAGS) $@ Set/DoublyLinkedList.c