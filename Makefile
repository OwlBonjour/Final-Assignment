main:main.o queue.o stack.o tree.o
	gcc main.o queue.o stack.o tree.o -o main
main.o:main.c
	gcc -c main.c
queue.o:queue.c
	gcc -c queue.c
stack.o:stack.c
	gcc -c stack.c
tree.o:tree.c
	gcc -c tree.c
clean:
	rm main *.o
