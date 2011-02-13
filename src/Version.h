/**
* @file Version.h
* Version information.
*
* @author Ryan "BioHazard" Turner <zdbiohazard2@gmail.com>
* @author Cody "QBasicer" Harris <charris@vectec.net>
* @date Copyright (c) 2011
*
* @section LICENSE
* This program is free software: you can redistribute it and/or modify it under
* the terms of the GNU General Public License as published by the Free Software
* Foundation, either version 3 of the License, or optionally any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU General Public License for details.
*/
#ifndef VERSION_H
#define VERSION_H

#ifndef ZDL_VERSION
	#define ZDL_VERSION "3.8.7"
#endif // ZDL_VERSION

#ifndef ZDL_REVISION
	#define ZDL_REVISION "Custom"
#endif // ZDL_REVISION

#ifndef ZDL_COMPILEDATE
	#define ZDL_COMPILEDATE "Unknown Compile Date"
#endif // ZDL_COMPILEDATE

#ifndef ZDL_BUILDINFO
	#define ZDL_BUILDINFO "Unknown Build"
#endif // ZDL_BUILDINFO

#ifndef ZDL_FULLVERSION
	#define ZDL_FULLVERSION ZDL_VERSION" ("ZDL_REVISION")"
#endif // ZDL_FULLVERSION

#ifndef ZDL_APPTITLE
	#define ZDL_APPTITLE "ZDL "ZDL_FULLVERSION
#endif // ZDL_APPTITLE

#endif // VERSION_H

