# Makefile for password generator.
# by foo74
all: main

pass_gen: main.c
	gcc main.c -Wall -g -c -o main.o
	gcc -o main main.o

run:
	./main

clean:
	rm main main.o output
