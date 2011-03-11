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

HEADERS = src/Version.h \
          src/QLabelLayout.h \
          src/ZDLApp.h \
          src/ZDLMainWindow.h \
          src/ZDLTab.h \
          src/ZDLTabMain.h \
          src/ZDLTabMulti.h

SOURCES = src/ZDL.cpp \
          src/ZDLApp.cpp \
          src/ZDLMainWindow.cpp \
          src/ZDLTab.cpp \
          src/ZDLTabMain.cpp \
          src/ZDLTabMulti.cpp

RESOURCES = res/ZDL.qrc

# Build information is platform-dependant.
unix {
	DEFINES += ZDL_VERSION="\"\\\"`git describe --always`\\\"\""
	DEFINES += ZDL_COMPILEDATE="\"\\\"`date +'%a, %b %d %Y %H:%M:%S %Z'`\\\"\""
	DEFINES += ZDL_BUILDINFO="\"\\\"`uname -mo` (Qt $${QT_VERSION})\\\"\""
	# Nobody likes case-sensitive binaries in 'nix. :p
	TARGET = "zdl"
} win32 {
	DEFINES += ZDL_BUILDINFO="\"\\\"Windows (Qt $${QT_VERSION})\\\"\""
}

# Use faster strings.
DEFINES += QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

# Disable debug messages in release mode.
release {
	DEFINES += QT_NO_DEBUG_STREAM
}

