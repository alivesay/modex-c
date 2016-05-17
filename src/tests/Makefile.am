AM_CFLAGS = \
	-I${top_srcdir}/include \
	-std=c99

TESTS = \
	check_slist

check_PROGRAMS = \
	check_slist

check_slist_SOURCES = \
	check_slist.c 

check_slist_CFLAGS = @CHECK_CFLAGS@ -I${top_srcdir}/include
check_slist_LDADD = ${top_srcdir}/src/libmodex/libmodex.la @CHECK_LIBS@

-include $(top_srcdir)/git.mk
