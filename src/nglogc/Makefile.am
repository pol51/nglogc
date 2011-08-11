# Makefile.am

AUTOMAKE_OPTIONS = foreign

# dynamic library build with libtool
lib_LTLIBRARIES= libnglogc.la

AM_CFLAGS = -Wall -std=c99
# seems that it is not possible with c99 to use variadic
# makros with the option -pedantic and build without warning
# when no variadic parameter is given in function call!
#AM_CFLAGS = -Wall -Werror -std=c99 -pedantic

libnglogc_la_LDFLAGS = -version-info 0:0:0
# libnglogc_la_LDFLAGS = -release 1.1.0 -version-info 0:0:0

libnglogc_la_SOURCES = $(nglogc_sources)

nglogc_sources = \
	logger.c \
	flf_log.c \
	flf_logtrace.c \
	flf_logarray.c \
	flf_logerror.c \
	nflf_log.c \
	nflf_logtrace.c \
	nflf_logarray.c \
	nflf_logerror.c \
	printout.h \
	printout.c \
	err_record.h \
	err_record.c \
	log_record.h \
	log_record.c \
	array_record.h \
	array_record.c \
	timestamp.h \
	timestamp.c \
	ringbuffer.h \
	ringbuffer.c

include_HEADERS = \
	logger_type.h \
	log.h \
	logger.h \
	flf_log.h \
	flf_logtrace.h \
	flf_logarray.h \
	flf_logerror.h \
	nflf_log.h \
	nflf_logtrace.h \
	nflf_logarray.h \
	nflf_logerror.h \
	types.h \
	log_priv.h

includedir = @includedir@/nglogc/


# unittests
check_PROGRAMS = unittests

unittests_SOURCES= \
	unittests.c \
	log.h \
	timestamp.h

unittests_CFLAGS = \
	-DLOGC_ENABLE_LOW_LEVEL

unittests_LDADD= \
	-L./.libs -lnglogc

TESTS=$(check_PROGRAMS)


