CONFIG = qt

    MOC_DIR = ./obj/
OBJECTS_DIR = ./obj/

DEFINES += ZDL_COMPILEDATE="\"\\\"`date +'%a, %b %d %Y %H:%M:%S %Z'`\\\"\""
DEFINES += ZDL_BUILDINFO="\"\\\"`uname -mo`\\\"\""
# TODO: Add a define for ZDL_REVISION that gets the Git hash or something.

HEADERS = src/Version.h \
          src/QLabelLayout.h \
          src/ZDLApp.h \
          src/ZDLMainWindow.h \
          src/ZDLTab.h \
          src/ZDLTabMain.h

SOURCES = src/ZDL.cpp \
          src/ZDLApp.cpp \
          src/ZDLMainWindow.cpp \
          src/ZDLTab.cpp \
          src/ZDLTabMain.cpp

