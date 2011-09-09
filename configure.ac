#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

dnl configure.in
AC_PREREQ(2.61)
AC_INIT([nglogc], [1.1.0], [ebrosius@netgarage.org])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/nglogc/logger.c])
AC_CONFIG_HEADER([src/nglogc/config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
#AC_PROG_RANLIB
AC_PROG_LIBTOOL

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h time.h stdint.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STRFTIME
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([
	Makefile
	doc/Makefile
	src/Makefile
	src/nglogc/Makefile])
AC_OUTPUT
