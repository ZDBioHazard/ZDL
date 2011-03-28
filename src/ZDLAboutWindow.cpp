/**
* @file ZDLAboutWindow.cpp
* ZDLAboutWindow class.
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
#include "ZDLAboutWindow.h"

///////////////////////////////////////////////////////////////////////////////
// Public Functions
///////////////////////////////////////////////////////////////////////////////

/**
* Instance generator for ZDLAboutWindow.
*
* @param  windowTitle  The new window's title.
*
* @return New ZDLAboutWindow object on success, NULL on failure.
*/
ZDLAboutWindow* ZDLAboutWindow::newInstance( QWidget *parentWidget ){
	qDebug() << "ZDLAboutWindow::newInstance: Creating a new ZDLAboutWindow instance.";
	try {
		ZDLAboutWindow *newAboutWindow = new ZDLAboutWindow(parentWidget);
		return newAboutWindow;
	} catch ( char const *except ){
		qCritical() << "ZDLAboutWindow::newInstance: Caught exception:" << except;
		return NULL;
	}
	qCritical() << "ZDLAboutWindow::newInstance: Something weird hapened!";
	return NULL; // Should never get here.
}

///////////////////////////////////////////////////////////////////////////////
// Protected Functions
///////////////////////////////////////////////////////////////////////////////

/**
* Constructor for ZDLAboutWindow.
*
* @param  windowTitle  The new window's title.
*/
ZDLAboutWindow::ZDLAboutWindow( QWidget *parentWidget ) : QDialog( parentWidget ){
	// Set some window properties.
	this->setWindowTitle("About ZDL");
	this->setWindowIcon(QIcon(":/zdlicon"));

	// Set up the main layout.
	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutMain);

	// Create the button down at the bottom.
	QHBoxLayout *layoutButton = new QHBoxLayout();
	QPushButton *buttonClose  = new QPushButton("Close", this);
	// Make sure all the widgets got created properly.
	if( !layoutButton || !buttonClose )
		throw "Couldn't create the Close button!";
	// Aaand add them to the layout.
	layoutButton->addStretch();
	layoutButton->addWidget(buttonClose);
	layoutMain->addLayout(layoutButton);

	// Connect the button signals.
	connect(buttonClose, SIGNAL(clicked()), this, SLOT(accept()));

	// Prep the window and show it.
	this->layout()->setSizeConstraint( QLayout::SetFixedSize ); // No resizing.
	this->show(); // Show before moving to update the internal window size.
}

