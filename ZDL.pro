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

SOURCES = \
	ZDL.cpp ZDLApp.cpp \
	ZDLMainWindow.cpp ZDLAboutWindow.cpp \
	ZDLTab.cpp ZDLTabMain.cpp ZDLTabMulti.cpp

RESOURCES = res/ZDL.qrc

# Use faster strings.
DEFINES += QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

# Nifty build information defines for Versions.h.
ZDL_VERSION   = $$system("git describe --tags --always")
!isEmpty(ZDL_VERSION):DEFINES += ZDL_VERSION="\"\\\"$${ZDL_VERSION}\\\"\""

# Windows builds do not like date.  It cases qmake to hang.
!win32{
	ZDL_TIMESTAMP = $$system("date +'%b %d %Y %H:%M:%S %Z'")
}
win32{
	ZDL_TIMESTAMP = "UNKNOWN"
}

!isEmpty(ZDL_TIMESTAMP):DEFINES += ZDL_TIMESTAMP="\"\\\"$${ZDL_TIMESTAMP}\\\"\""

# Platform is special because we always want the Qt version.
!win32{
	ZDL_PLATFORM  = $$system("uname -mo")
}
win32{
	ZDL_PLATFORM = "Windows"
}
isEmpty(ZDL_PLATFORM):ZDL_PLATFORM = "Unknown Platform"
DEFINES += ZDL_PLATFORM="\"\\\"$${ZDL_PLATFORM} (Qt $${QT_VERSION})\\\"\""

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

