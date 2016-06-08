# Makefile for password generator.
# by foo74
all: ask

ask: ask.c ask.h
	gcc ask.c -Wall -g -c -o ask.o
	gcc -o ask ask.o

run:
	./ask

clean:
	rm ask ask.o output
