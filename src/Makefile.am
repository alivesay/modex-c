SUBDIRS = libmodex tests

AM_CFLAGS = \
	-I${top_srcdir}/include \
	-std=c99

bin_PROGRAMS = modex

modex_SOURCES = \
	main.c

modex_LDADD = ${top_srcdir}/src/libmodex/libmodex.la

-include $(top_srcdir)/git.mk
