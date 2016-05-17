AC_INIT([modex], [0.1.0])
AM_INIT_AUTOMAKE([foreign subdir-objects])

IT_PROG_INTLTOOL(0.40.0)
GETTEXT_PACKAGE=AC_PACKAGE_NAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE",[modex])

AC_PROG_CC

LT_INIT

PKG_CHECK_MODULES(MODEX, [
    gl >= 11.2.1,
    sdl2 >= 2.0.4
])

PKG_CHECK_MODULES(CHECK, [ check >= 0.9.10 ])

AC_CONFIG_FILES([
	Makefile
	po/Makefile.in
    src/libmodex/Makefile
    src/tests/Makefile
	src/Makefile
])

AC_OUTPUT
