
Debian
====================
This directory contains files used to package QuestionIVd/QuestionIV-qt
for Debian-based Linux systems. If you compile QuestionIVd/QuestionIV-qt yourself, there are some useful files here.

## pivx: URI support ##


QuestionIV-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install QuestionIV-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your QuestionIV-qt binary to `/usr/bin`
and the `../../share/pixmaps/pivx128.png` to `/usr/share/pixmaps`

QuestionIV-qt.protocol (KDE)

