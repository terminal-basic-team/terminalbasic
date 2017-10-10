AUTOMAKE_OPTIONS = foreign

#
# Subdirectories in which more makefiles can be found
#
SUBDIRS = terminal-basic

#
# List of data files in this directory that should be included with a tkgate distribution.
#
#dist_pkgdata_DATA = site-preferences

#
# List of common documentation files
#
dist_doc_DATA = README COPYING ChangeLog

#
# Update the release data for this compilation
#
release:
	echo 'const char *release_date = "'`(LANG=; date "+%b %d %Y")`'";' > $(srcdir)/src/verga/release.cpp

dist-hook:
	@echo Packaging data files...
	@for d in $(VG_DISTITEMS); do \
	   cp -pR $(srcdir)/$$d $(distdir); \
	done

tests:
	cd test/verga;./runtests.sh
#
# Copy all the data files we need
#
install-data-hook:
	@echo Installing data files...
	@for d in $(TKG_DATADIRS); do \
	   cp -pR $(srcdir)/$$d $(DESTDIR)$(pkgdatadir); \
	done

uninstall-local:
	@echo Uninstalling data files...
	@for d in $(VG_DATADIRS); do \
	   chmod -R u+w $(DESTDIR)$(pkgdatadir)/$$d; \
	   rm -rf $(DESTDIR)$(pkgdatadir)/$$d; \
	done

