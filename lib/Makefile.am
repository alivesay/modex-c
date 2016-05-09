AM_CFLAGS = \
	-I${top_srcdir}/include \
	-I${top_srcdir}/lib \
	-Wall \
	-std=c99 \
	-pthread \
	-D_REENTRANT

AM_LDFLAGS = \
	-lepoxy \
	-lGL \
    -lSDL2

noinst_LTLIBRARIES = libmodex.la

libmodex_la_SOURCES = \
	core/mx_color.c \
	core/mx_log.c \
	core/mx_math.c \
	core/mx_memory.c \
	core/mx_util.c \
    core/mx_video.c \
	gl/mx_gl_common.c \
	gl/mx_gl_program.c

-include $(top_srcdir)/git.mk
