run: main
	valgrind ./main 

main: main.o tree.o
	gcc *.o -o main -Wall -g

main.o: main.c tree.h
	gcc -c main.c -Wall -g

tree.o: tree.c tree.h
	gcc -c tree.c -Wall -g 

clean: 
	rm -r *.o
	rm -f main
	clear
	ls -l