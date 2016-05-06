AC_INIT([modex], [0.1.0])
AM_INIT_AUTOMAKE([foreign subdir-objects])

IT_PROG_INTLTOOL(0.40.0)
GETTEXT_PACKAGE=AC_PACKAGE_NAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE",[modex])

AC_PROG_CC

LT_INIT

PKG_CHECK_MODULES(MODEX, [
    epoxy >= 1.3.1,
    glfw3 >= 3.1.2,
    gl >= 11.2.1
])

AC_CONFIG_FILES([
	Makefile
	po/Makefile.in
    lib/Makefile
	src/Makefile
])

AC_OUTPUT
