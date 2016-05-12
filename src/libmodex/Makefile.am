AM_CFLAGS = \
	-I${top_srcdir}/src/libmodex \
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
	gl/mx_gl_common.c \
	gl/mx_gl_program.c \
    core/mx_video.c 

modex.h: libmodex.la
	@echo -e "#ifndef H_MODEX\n#define H_MODEX\n" \
		> ${top_srcdir}/include/modex.h \
	&& cat \
		core/mx_types.h \
		core/mx_color.h \
		core/mx_log.h \
		core/mx_math.h \
		core/mx_memory.h \
		core/mx_util.h \
		gl/mx_gl_common.h \
		gl/mx_gl_vbo.h \
		gl/mx_gl_program.h \
		core/mx_video.h \
		>> ${top_srcdir}/include/modex.h \
	&& echo -e "\n#endif // H_MODEX" \
		>> ${top_srcdir}/include/modex.h

all: modex.h

-include $(top_srcdir)/git.mk
