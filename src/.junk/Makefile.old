# Makefile for password generator.
# by foo74
all: transforms pass_gen

transforms: transforms/transforms.c transforms/transforms.h transforms/transforms.o
	cd transforms; make

pass_gen: pass_gen.c pass_gen.h
	gcc pass_gen.c -Wall -g -c -o pass_gen.o
	gcc -o pass_gen transforms/transforms.o pass_gen.o

run:
	./pass_gen -t

clean:
	cd transforms; make clean
	rm pass_gen pass_gen.o output
