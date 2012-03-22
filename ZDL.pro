###############################################################################
# ZDL.pro
# ZDL qmake project file.
#
# Author: Ryan "BioHazard" Turner <zdbiohazard2@gmail.com>
# Author: Cody "QBasicer" Harris <charris@vectec.net>
# Copyright (c) 2011
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or optionally any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for details.
###############################################################################

# This needs to be += so you can specify debug mode on the qmake command line.
CONFIG += qt resources

# Put all the temp files in another directory.
MOC_DIR     = obj/
OBJECTS_DIR = obj/
RCC_DIR     = obj/
INCLUDEPATH = src/
DEPENDPATH  = src/

HEADERS = \
	Version.h QLabelLayout.h ZDLApp.h \
	ZDLMainWindow.h ZDLAboutWindow.h \
	ZDLTab.h ZDLTabMain.h ZDLTabMulti.h \
	generated.h

SOURCES = \
	ZDL.cpp ZDLApp.cpp \
	ZDLMainWindow.cpp ZDLAboutWindow.cpp \
	ZDLTab.cpp ZDLTabMain.cpp ZDLTabMulti.cpp

RESOURCES = res/ZDL.qrc

# Use faster strings.
DEFINES += QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

FOO = $$system("bash generate.sh $${QT_VERSION}}");

#QMAKE_CXXFLAGS += -I.
QMAKE_CXXFLAGS += -include generated.h
win32{
	message("Statically compiling libstdc++ and libgcc");
	QMAKE_CXXFLAGS += -static-libgcc -static-libstdc++
}
INCLUDEPATH += ./

# Disable debug messages in release mode.
CONFIG(release, debug|release){
	message("Release version, disabling debug messages.")
	DEFINES += QT_NO_DEBUG_STREAM
}

# Platform-specific stuff.
unix {
	# Nobody likes case-sensitive binaries in 'nix. :p
	message("building for 'nix, the binary will be lowercase. ;)")
	TARGET = "zdl"
}

