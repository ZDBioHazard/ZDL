/**
* @file ZDLApp.cpp
* ZDLApp class.
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

/**
* Instance generator for ZDLApp.
*
* @param  argc  Number of command line paramaters to feed to ZDLApp().
* @param  argv  List of command line paramaters to feed to ZDLApp().
*
* @return New ZDLApp object on success, NULL on failure.
*/
ZDLApp* ZDLApp::newInstance( int &argc, char **argv ){
	qDebug() << "ZDLApp::newInstance: Creating a new ZDLApp instance.";
	try {
		ZDLApp *newApp = new ZDLApp(argc, argv);
		return newApp;
	} catch ( char const *except ){
		qCritical() << "ZDLApp::newInstance: Caught exception:" << except;
		return NULL;
	}
	qCritical() << "ZDLApp::newInstance: Something weird hapened!";
	return NULL; // Should never get here.
}

/**
* Constructor for ZDLApp.
*
* @param  argc  Number of command line paramaters.
* @param  argv  List of command line paramaters.
*/
ZDLApp::ZDLApp( int &argc, char **argv ) : QApplication( argc, argv ){
	// Set-up the main window.
	this->mainWindow = ZDLMainWindow::newInstance(ZDL_APPTITLE);
	if( !this->mainWindow ) // Check if the object is okay.
		throw "Couldn't create the mainWindow!";
}

