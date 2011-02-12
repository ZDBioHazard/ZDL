/**
* @file ZDLMainWindow.cpp
* ZDLMainWindow class.
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
#include "ZDLMainWindow.h"

/**
* Instance generator for ZDLMainWindow.
*
* @return New ZDLMainWindow object on success, NULL on failure.
*/
ZDLMainWindow* ZDLMainWindow::newInstance( QString windowTitle ){
	ZDLMainWindow *newMainWindow = new ZDLMainWindow(windowTitle);
	if( newMainWindow->getInitOK() == FALSE ){
		// TODO: Error report here.
		return NULL;
	}
	return newMainWindow;
}

/**
* Get the object's initialization status.
*
* @return the object's initStatus.
*/
bool ZDLMainWindow::getInitOK( ){
	return this->initOK;
}

/**
* Constructor for ZDLMainWindow.
*
* @param  windowTitle  The new window's title.
*/
ZDLMainWindow::ZDLMainWindow( QString windowTitle ) : QWidget( ){
	this->initOK = FALSE; // Initialize the object status.
	this->setWindowTitle(windowTitle);

	// Set up the main layout.
	QVBoxLayout *layoutMain = new QVBoxLayout();
	this->setLayout(layoutMain);

	// Time to show it and get outta' here.
	this->show();
	this->initOK = TRUE; // Class is good to go!
}

