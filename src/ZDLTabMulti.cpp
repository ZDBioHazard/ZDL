/**
* @file ZDLTabMulti.cpp
* ZDLTabMulti class.
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
#include "ZDLTabMulti.h"

/**
* Instance generator for ZDLTabMulti.
*
* @return New ZDLTabMulti object on success, NULL on failure.
*/
ZDLTabMulti* ZDLTabMulti::newInstance( QWidget *parentWidget ){
	ZDLTabMulti *newTab = new ZDLTabMulti(parentWidget);
	if( newTab->getInitOK() != TRUE ){
		// TODO: Error report here.
		return NULL;
	}
	return newTab;
}

/**
* Constructor for ZDLTabMulti.
*
* @param  parentWidget  Parent widget to assign this widget to.
*/
ZDLTabMulti::ZDLTabMulti( QWidget *parentWidget ) : ZDLTab( parentWidget ){
	this->initOK = FALSE; // Initialize the object status.

	// Set the tab name.
	this->tabLabel = "Multiplayer";

	//
	// NOTE: The indentation in this function sort-of
	//       illustrates how the widgets are nested.
	//

	// Set up the main layout.
	QGridLayout *layoutTab = new QGridLayout();
	layoutTab->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutTab);

	// TODO: Game Mode
	// TODO: Players
	// TODO: Host Name
	// TODO: Port
	// TODO: Frag Limit
	// TODO: Time Limit
	// TODO: DUP
	// TODO: Extratic

	// Looks like we're done here. ...Finally.
	this->initOK = TRUE; // Class is good to go!
}

