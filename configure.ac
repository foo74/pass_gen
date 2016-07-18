#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([pass_gen], [0.1], [foo@none.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
#AC_SUBST([AM_CXXFLAGS], [-Wall -static])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([strcspn])

AC_CONFIG_FILES([Makefile
                 data/Makefile
                 examples/Makefile
                 doc/Makefile
                 man/Makefile
                 src/Makefile])
AC_OUTPUT 
