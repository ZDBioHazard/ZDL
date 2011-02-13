CONFIG = qt

    MOC_DIR = ./obj/
OBJECTS_DIR = ./obj/

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

unix {
	DEFINES += ZDL_VERSION="\"\\\"`git describe --always`\\\"\""
	DEFINES += ZDL_COMPILEDATE="\"\\\"`date +'%a, %b %d %Y %H:%M:%S %Z'`\\\"\""
	DEFINES += ZDL_BUILDINFO="\"\\\"`uname -mo` (Qt $${QT_VERSION})\\\"\""
} win32 {
	DEFINES += ZDL_BUILDINFO="\"\\\"Windows (Qt $${QT_VERSION})\\\"\""
}

