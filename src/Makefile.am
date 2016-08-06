# Flags to pass to compiler and linker.
AM_CFLAGS = -Wall -g -std=c99 -O2
AM_LDFLAGS =
AUTOMAKE_OPTIONS=subdir-objects
# List the binaries and their sources.
bin_PROGRAMS = pass_gen
pass_gen_SOURCES = \
	pass_gen.c pass_gen.h \
	utils/build_input.c utils/build_input.h \
	utils/buffer_tools.c utils/buffer_tools.h \
	utils/file_tools.c utils/file_tools.h \
	transforms/numbers.c transforms/numbers.h \
	transforms/characters.c transforms/characters.h \
	transforms/symbols.c transforms/symbols.h
	
# Location to install below installs in ()/bin or ()/sbin
