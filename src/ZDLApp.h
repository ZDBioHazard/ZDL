/**
* @file ZDLApp.h
* ZDLApp class header.
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
#ifndef ZDLAPP_H
#define ZDLAPP_H

#include "ZDLMainWindow.h"

// Qt Stuff.
#include <QDebug>
#include <QtGui/QApplication>

/**
* @class ZDLApp
* Main application class.
*/
class ZDLApp : public QApplication {
	public:
	// Public Functions.
		static ZDLApp* newInstance( int &argc, char **argv );

	protected:
	// Protected Variables.
		bool           initOK;     ///< Object initialization status.
		ZDLMainWindow *mainWindow; ///< Main window.

	// Protected Functions.
		bool getInitOK( );
		        ZDLApp( int &argc, char **argv );
};

#endif // ZDLAPP_H

