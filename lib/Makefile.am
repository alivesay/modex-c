AM_CFLAGS = -I${top_srcdir}/include -Wall -std=c99 -pthread -D_REENTRANT

AM_LDFLAGS = \
	-lepoxy \
	-lGL \
    -lSDL2

noinst_LTLIBRARIES = libmodex.la

libmodex_la_SOURCES = \
    mx_video.c

-include $(top_srcdir)/git.mk
