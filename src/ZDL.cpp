/**
* @file ZDL.cpp
* Application entry point.
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
#include "ZDLApp.h"

/// Yay entry point!
int main( int argc, char **argv ){
	ZDLApp *zdl = ZDLApp::newInstance(argc, argv);
	if( zdl == NULL ) // Check if the object is okay.
		return 1;
	return zdl->exec();
}

