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
ZDLApp* ZDLApp::newInstance( int argc, char **argv ){
	ZDLApp *newApp = new ZDLApp(argc, argv);
	if( newApp->getInitOK() == FALSE ){
		// TODO: Error report here.
		return NULL;
	}
	return newApp;
}

/**
* Get the object's initialization status.
*
* @return the object's initStatus.
*/
bool ZDLApp::getInitOK( ){
	return this->initOK;
}

/**
* Constructor for ZDLApp.
*
* @param  argc  Number of command line paramaters.
* @param  argv  List of command line paramaters.
*/
ZDLApp::ZDLApp( int argc, char **argv ) : QApplication( argc, argv ){
	this->initOK = FALSE; // Initialize the object status.

	// Set-up the main window.
	this->mainWindow = ZDLMainWindow::newInstance();
	if( this->mainWindow == NULL ){ // Check if the object is okay.
		// TODO: Error report here.
		return;
	}

	this->initOK = TRUE; // Class is good to go!
}

