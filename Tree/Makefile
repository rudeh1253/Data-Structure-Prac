app.out: BinaryTree.o main.o
	gcc -o app.out BinaryTree.o main.o

main.o: BinaryTree.h execution1.c
	gcc -c -o main.o execution1.c

BinaryTree.o: BinaryTree.h BinaryTree.c
	gcc -c -o BinaryTree.o BinaryTree.c