CC=gcc
OBJFLAGS=-c -o
OBJS=execution3.o LinkedListSet.o DoublyLinkedList.o SetOperation.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CC) $(OBJS)

execution3.o: LinkedListSet.h LinkedList.h SetOperation.h execution2.c
	$(CC) $(OBJFLAGS) $@ execution3.c

LinkedListSet.o: LinkedList.h LinkedListSet.h LinkedListSet.c
	$(CC) $(OBJFLAGS) $@ LinkedListSet.c

DoublyLinkedList.o: LinkedList.h DoublyLinkedList.c
	$(CC) $(OBJFLAGS) $@ DoublyLinkedList.c

SetOperation.o: SetOperation.h LinkedListSet.h LinkedList.h SetOperation.c
	$(CC) $(OBJFLAGS) $@ SetOperation.c

clean:
	rm *.o
	rm ${TARGET}