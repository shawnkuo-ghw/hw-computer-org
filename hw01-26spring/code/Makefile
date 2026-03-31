.PHONY: compile
.PHONY: clean

compile: stdlib_test

stdlib_test: main.o string.o math.o boolean.o
	gcc main.o string.o math.o boolean.o -o stdlib_test

main.o: main.c
	gcc -c main.c -o main.o

string.o: string.c
	gcc -c string.c -o string.o

math.o: math.c
	gcc -c math.c -o math.o

boolean.o: boolean.c
	gcc -c boolean.c -o boolean.o

clean:
	find . -name '*.o' -delete
	find . -name 'stdlib_test' -delete