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
	/// Simple version number.
	/// The full value is set by defines in ZDL.pro when possible.
	#define ZDL_VERSION "3.8.7"
#endif // ZDL_VERSION

#ifndef ZDL_COMPILEDATE
	/// Compile date. Should be readable by people.
	/// The full value is set by defines in ZDL.pro when possible.
	#define ZDL_COMPILEDATE "Unknown Compile Date"
#endif // ZDL_COMPILEDATE

#ifndef ZDL_BUILDINFO
	/// Build information. Should include OS and Architecture.
	/// The full value is set by defines in ZDL.pro when possible.
	#define ZDL_BUILDINFO "Unknown Build"
#endif // ZDL_BUILDINFO

#ifndef ZDL_APPTITLE
	/// Application Title, including version number.
	// TODO: Should support i18n.
	#define ZDL_APPTITLE "ZDL "ZDL_VERSION
#endif // ZDL_APPTITLE

#endif // VERSION_H

