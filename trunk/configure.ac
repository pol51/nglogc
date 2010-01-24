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
AC_PROG_RANLIB
# to build dynamic libraries
#AC_PROG_LIBTOOL

# Checks for libraries.
#AC_CHECK_LIB([pthread], [pthread_create], , AC_MSG_ERROR([pthread lib not found]))
#AC_CHECK_LIB([crypto], [DES_set_key], , AC_MSG_ERROR([crypto lib not found]))

# Set defines.
#AC_DEFINE([_GNU_SOURCE],[1],[Define GNU extensions])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdint.h stdlib.h string.h stdio.h getopt.h stdarg.h signal.h])
#AC_CHECK_HEADER([pthread.h],, AC_MSG_ERROR([pthread.h not found]))
#AC_CHECK_HEADER([openssl/des.h],, AC_MSG_ERROR([openssl/des.h not found]))
#AC_CHECK_HEADER([openssl/sha.h],, AC_MSG_ERROR([openssl/sha.h not found]))

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
