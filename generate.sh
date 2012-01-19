#!/bin/bash

if [[ $# -ne 1 ]]; then
	QTVER="N/A"
else
	QTVER=$1
fi

OUTPUT=generated.h

echo "Creating ZDL define include at $OUTPUT"

ZDL_VERSION=`git describe --tags --always`
rm -rf $OUTPUT
echo "/*******************************************/" > $OUTPUT
echo "/* This is an automatically generated file */" >> $OUTPUT
echo "/* Please do not modify it directly        */" >> $OUTPUT
echo "/*******************************************/" >> $OUTPUT
echo "" >> $OUTPUT
echo "// ZDL Version" >> $OUTPUT
echo "#define ZDL_VERSION \"${ZDL_VERSION}\"" >> $OUTPUT
echo "" >> generated.h
echo "ZDL Version: ${ZDL_VERSION}"


ZDL_TIMESTAMP="UNKNOWN"
echo "//ZDL build date - when qmake was last run" >> $OUTPUT
echo "#define ZDL_TIMESTAMP \"${ZDL_TIMESTAMP}\"" >> $OUTPUT
echo "" >> $OUTPUT
echo "ZDL Timestamp: ${ZDL_TIMESTAMP}"

ZDL_PLATFORM=`uname -mo`
ZDL_PLATFORM="${ZDL_PLATFORM} (Qt ${QTVER})"
echo "// ZDL Version identifier" >> $OUTPUT
echo "#define ZDL_PLATFORM \"${ZDL_PLATFORM}\"" >> $OUTPUT
echo "ZDL Platform: ${ZDL_PLATFORM}"

echo "Generation complete"
