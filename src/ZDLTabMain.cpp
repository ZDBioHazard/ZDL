/**
* @file ZDLTabMain.cpp
* ZDLTabMain class.
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
#include "ZDLTabMain.h"

/**
* Instance generator for ZDLTabMain.
*
* @return New ZDLTabMain object on success, NULL on failure.
*/
ZDLTabMain* ZDLTabMain::newInstance( QWidget *parentWidget ){
	ZDLTabMain *newTab = new ZDLTabMain(parentWidget);
	if( newTab->getInitOK() != TRUE ){
		// TODO: Error report here.
		return NULL;
	}
	return newTab;
}

/**
* Constructor for ZDLTabMain.
*
* @param  parentWidget  Parent widget to assign this widget to.
*/
ZDLTabMain::ZDLTabMain( QWidget *parentWidget ) : ZDLTab( parentWidget ){
	this->initOK = FALSE; // Initialize the object status.

	// This tab be called Jimmy!
	this->tabLabel = "General";

	// Set up the main layout.
	QVBoxLayout *layoutTab = new QVBoxLayout();
	layoutTab->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutTab);

	// Extra Args box.
	QLabelLayout *labelExtraArgs = new QLabelLayout("Extra Command-Line Arguments", this);
	        this->editExtraArgs  = new QLineEdit(this);
	if( !labelExtraArgs || !this->editExtraArgs ){
		// TODO: Error report here.
		return; // Bail out.
	}
	labelExtraArgs->addWidget(this->editExtraArgs);
	layoutTab->addLayout(labelExtraArgs);

	// Looks like we're done here.
	this->initOK = TRUE; // Class is good to go!
}

