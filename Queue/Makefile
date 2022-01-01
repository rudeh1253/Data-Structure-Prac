a.out: execution1.o ArrayQueue.o
	gcc -o a.out execution1.o ArrayQueue.o

execution1.o: ArrayQueue.h execution1.c
	gcc -c -o execution1.o execution1.c

ArrayQueue.o: ArrayQueue.h ArrayQueue.c
	gcc -c -o ArrayQueue.o ArrayQueue.c