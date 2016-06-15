#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([pass_gen], [0.0.1], [foo74@protonmail.ch])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([strcspn strstr])

AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 examples/Makefile
                 man/Makefile
                 scripts/Makefile
                 src/Makefile])
AC_OUTPUT
