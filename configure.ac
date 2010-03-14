#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

dnl configure.in
AC_PREREQ(2.61)
AC_INIT([nglogc], [0.0.1], [ebrosius@netgarage.org])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/nglogc/logger.c])
AC_CONFIG_HEADER([src/nglogc/config.h])

# Checks for programs.
AC_PROG_CC
## ranlib is deprecated?
#AC_PROG_RANLIB
# to build dynamic libraries
AC_PROG_LIBTOOL

# Set defines.
#AC_DEFINE([_GNU_SOURCE],[1],[Define GNU extensions])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdint.h stdlib.h string.h stdio.h stdarg.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T


# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strstr])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/nglogc/Makefile])
AC_OUTPUT
