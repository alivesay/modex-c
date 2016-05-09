AM_CFLAGS = \
	-I${top_srcdir}/include \
	-I${top_srcdir}/lib \
	-std=c99

bin_PROGRAMS = modex

modex_SOURCES = \
	main.c

modex_LDADD = ../lib/libmodex.la

-include $(top_srcdir)/git.mk
