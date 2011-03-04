/**
* @file ZDLTab.cpp
* ZDLTab class.
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
#include "ZDLTab.h"

/**
* Instance generator for ZDLTab.
*
* @param  parentWidget  Parent widget to assign this widget to.
*
* @return New ZDLTab object on success, NULL on failure.
*/
ZDLTab* ZDLTab::newInstance( QWidget *parentWidget ){
	qDebug() << "ZDLTab: Creating a new instance.";
	ZDLTab *newTab = new ZDLTab(parentWidget);
	if( newTab->getInitOK() == FALSE ){
		qCritical() << "ZDLTab: Couldn't create a new instance!";
		return NULL;
	}
	return newTab;
}

/**
* Get the object's initialization status.
*
* @return the object's initStatus.
*/
bool ZDLTab::getInitOK( ){
	return this->initOK;
}

/**
* Constructor for ZDLTab.
*
* @param  parentWidget  Parent widget to assign this widget to.
*/
ZDLTab::ZDLTab( QWidget *parentWidget ) : QWidget( parentWidget ){
	this->initOK = FALSE; // Initialize the object status.

	// Make sure the tab has a label.
	this->tabLabel = "Base Tab Object";

	this->initOK = TRUE; // Class is good to go!
}

/**
* Get the tab's label.
*
* @return the tab's label.
*/
QString ZDLTab::getTabLabel( ){
	return this->tabLabel;
}

