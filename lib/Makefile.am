AM_CFLAGS = -I${top_srcdir}/include -Wall -std=c99

AM_LDFLAGS = \
	-lepoxy \
    -lglfw \
	-lGL \
	-lX11 \
	-lXrandr \
	-lXi \
	-lpthread 

noinst_LTLIBRARIES = libmodex.la

libmodex_la_SOURCES = \
    mx_video.c

-include $(top_srcdir)/git.mk
