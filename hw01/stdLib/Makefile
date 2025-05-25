# Complete with tasks for:
# 1. compile everything
# 2. compile just boolean.c
# 3. compile just math.c
# 4. compile just strings.c

assignment1: main.o boolean.o math.o strings.o
	gcc main.o boolean.o math.o strings.o -o assignment1

main.o: main.c
	gcc -c main.c -o main.o

boolean.o: boolean.c
	gcc -c boolean.c -o boolean.o

math.o: math.c
	gcc -c math.c -o math.o

strings.o: strings.c
	gcc -c strings.c -o strings.o

.PHONY: clean

clean:
	find . -name '*.o' -delete
	find . -name 'assignment1' -delete