SUBDIRS = po lib src

AM_CFLAGS = -I${top_srcdir}/include -std=c99

MAINTAINERCLEANFILES = \
	$(GITIGNORE_MAINTAINERCLEANFILES_TOPLEVEL) \
	$(GITIGNORE_MAINTAINERCLEANFILES_MAKEFILE_IN) \
	configure \
	$(NULL)

-include $(top_srcdir)/git.mk
