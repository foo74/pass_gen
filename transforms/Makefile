# Makefile for password generator.
# by foo74
all: pass_gen

pass_gen: pass_gen.c pass_gen.h
	gcc pass_gen.c -Wall -g -c -o pass_gen.o
	gcc -o pass_gen pass_gen.o

run:
	./pass_gen
	cat input pass1 pass2 pass3 > output

clean:
	rm pass_gen pass_gen.o pass1 pass2 pass3 output output2
