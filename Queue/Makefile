a.out: execution2.o LinkedListQueue.o
	gcc -o a.out execution2.o LinkedListQueue.o

execution2.o: LinkedListQueue.h execution2.c
	gcc -c -o execution2.o execution2.c

LinkedListQueue.o: LinkedListQueue.h LinkedListQueue.c
	gcc -c -o LinkedListQueue.o LinkedListQueue.c

clean:
	rm *.o
	rm a.out