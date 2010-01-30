# Makefile.am

AUTOMAKE_OPTIONS = foreign

# static library
lib_LIBRARIES = libnglogc.a

# dynamic library build with libtool
#lib_LTLIBRARIES= libnglogc.la

#bin_PROGRAMS = nglibc

AM_CFLAGS = -Wall -Werror -std=c99
# seems that it is not possible with c99 to use variadic
# makros with the option -pedantic and build without warning
# when no variadic parameter is given in function call!
#AM_CFLAGS = -Wall -Werror -std=c99 -pedantic

libnglogc_a_SOURCES = \
	log.h \
	log_priv.h \
	logger.h \
	logger.c \
	flf_log.h \
	flf_log.c \
	nflf_log.h \
	nflf_log.c \
	printout.h \
	printout.c \
	record.h \
	record.c \
	types.h


check_PROGRAMS = unittests

unittests_SOURCES= \
	unittests.c \
	log.h

#unittests_LDFLAGS=
unittests_LDADD= \
	-L . -lnglogc

TESTS=$(check_PROGRAMS)


