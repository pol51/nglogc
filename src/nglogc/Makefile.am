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

libnglogc_la_SOURCES = $(nglogc_sources)

nglogc_sources = \
	logger.c \
	flf_log.c \
	nflf_log.c \
	printout.c \
	err_record.c \
	log_record.c \
	array_record.c \
	timestamp.c

include_HEADERS = \
	logger_type.h \
	log_record.h \
	log.h \
	config.h \
	printout.h \
	timestamp.h \
	err_record.h \
	logger.h \
	flf_log.h \
	types.h \
	array_record.h \
	nflf_log.h \
	log_priv.h

includedir = @includedir@/nglogc/


# unittests
check_PROGRAMS = unittests unittests_flf

unittestsIncludes = log.h timestamp.h
unittestsLdadd = -L./libs -lnglogc

unittests_SOURCES= \
	unittests.c \
	$(unittestsIncludes)

unittests_CFLAGS = \
	-DLOGC_ENABLE_LOW_LEVEL

unittests_LDADD= \
	$(unittestsLdadd)


unittests_flf_SOURCES= \
	unittests_flf.c \
	$(unittestsIncludes)

unittests_flf_CFLAGS = \
	-DLOGC_ENABLE_LOW_LEVEL \
	-DLOGC_HAVE_FLF

unittests_flf_LDADD= \
	$(unittestsLdadd)


TESTS=$(check_PROGRAMS)


