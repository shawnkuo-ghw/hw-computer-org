.PHONY: compile
.PHONY: clean

compile: system

system: system.o out.o main.o sstd.h
	gcc -o system system.o out.o main.o

system.o: system.c sstd.h
	gcc -c -o system.o system.c

out.o: out.c sstd.h
	gcc -c -o out.o out.c

main.o: main.c sstd.h
	gcc -c -o main.o main.c

clean:
	find . -name '*.o' -delete
	find . -name 'system' -delete