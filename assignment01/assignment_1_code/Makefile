.PHONY: compile
.PHONY: clean

compile: stdlib_test

stdlib_test: strings.o math.o boolean.o #TODO: add missing dependencies
# TODO: add command (the command must start after a tab)

strings.o: standard.h #TODO: add missing dependencies
# TODO: add command (the command must start after a tab)

clean:
	find . -name '*.o' -delete
	find . -name 'stdlib_test' -delete