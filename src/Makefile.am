# Flags to pass to compiler and linker.
AM_CFLAGS = -Wall -g -std=c99 -O2
AM_LDFLAGS =
AUTOMAKE_OPTIONS=subdir-objects
# List the binaries and their sources.
bin_PROGRAMS = pass_gen
pass_gen_SOURCES = pass_gen.c pass_gen.h transforms/transforms.c transforms/transforms.h ask.c
# Location to install below installs in ()/bin or ()/sbin
bin_SCRIPTS = questions
