AM_CFLAGS = \
	-I${top_srcdir}/src/libmodex \
	-I${top_srcdir}/src/libmodex/ext \
	-Wall \
	-std=c11 \
	-pthread \
	-D_REENTRANT \
	-g

AM_LDFLAGS = \
	-ldl \
	-lm \
	-lGL \
    -lSDL2

noinst_LTLIBRARIES = libmodex.la

libmodex_la_SOURCES = \
	core/mx_util.c \
	core/mx_memory.c \
	core/mx_color.c \
	core/mx_log.c \
	core/mx_math.c \
	core/mx_matrix4.c \
	core/mx_vector.c \
	core/mx_slist.c \
	core/mx_uintpool.c \
	core/mx_uintmap.c \
	\
	ext/glad/glad.c \
	\
	sdl/mx_sdl.c \
	sdl/mx_sdl_screen.c \
	\
	gl/mx_gl_common.c \
	gl/mx_gl_info.c \
	gl/mx_gl_program.c \
	gl/mx_gl_resourcemanager.c \
	gl/mx_gl.c \
    core/mx_video.c \
	\
	mx_modex.c

modex.h: libmodex.la
	@echo -e "#ifndef H_MODEX\n#define H_MODEX\n" \
		> ${top_srcdir}/include/modex.h \
	&& cat \
		core/mx_types.h \
		core/mx_util.h \
		core/mx_memory.h \
		core/mx_color.h \
		core/mx_log.h \
		core/mx_math.h \
		core/mx_matrix4.h \
		core/mx_vector.h \
		core/mx_slist.h \
		core/mx_uintpool.h \
		core/mx_uintmap.h \
		\
		ext/glad/glad.h \
		\
		sdl/mx_sdl.h \
		sdl/mx_sdl_screen.h \
		\
		gl/mx_gl_common.h \
		gl/mx_gl_info.h \
		gl/mx_gl_vbo.h \
		gl/mx_gl_program.h \
		gl/mx_gl_resourcemanager.h \
		gl/mx_gl.h \
		core/mx_video.h \
		\
		mx_modex.h \
		>> ${top_srcdir}/include/modex.h \
	&& echo -e "\n#endif // H_MODEX" \
		>> ${top_srcdir}/include/modex.h

all: modex.h

-include $(top_srcdir)/git.mk
