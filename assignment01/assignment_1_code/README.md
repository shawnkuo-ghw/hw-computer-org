# Lab 1

A `standard.h` header defines a "standard library" which we want to implement. The library contains
boolean, math, and strings functions and types. Instead of writing a monolithic implementation of our
standard library's header, we want to separate our implementation into `boolean`, `math`, and `strings`.

We also want to avoid the need to input compilation and cleaning commands every time we want to compile, and
clean our project. To tackle this problem we will define a `Makefile` with at least one *compile* task, and
one *clean* task.

Finally, we want to test our library, for this we will complete a `main.c` file to test all `standard.h`
functions.
