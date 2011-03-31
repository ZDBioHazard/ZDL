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
	this->setWindowTitle(tr("About ZDL"));
	this->setWindowIcon(QIcon(":/zdlicon"));

	// Set up the main layout.
	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutMain);

	// Display the logo at the top.
	QHBoxLayout *layoutLogo = new QHBoxLayout();
	QLabel      *labelLogo  = new QLabel("ZDL Logo", this);
	QLabel      *labelTitle = new QLabel("v"ZDL_VERSION, this);
	                                     // The <b> tags are to make the &copy; work.
	QLabel      *labelCopy  = new QLabel("<b>&copy; 2011 Ryan Turner / Vectec Software</b>", this);
	if( !layoutLogo || !labelLogo || !labelTitle || !labelCopy )
		throw "Couldn't create the logo area!";
	layoutLogo->setSpacing(32); // Put some space between the logo and version.
	labelLogo->setPixmap(QPixmap(":/zdlicon"));
	labelTitle->setFont(QFont("", 16)); // Bigger font.
	labelCopy->setAlignment(Qt::AlignCenter);

	layoutLogo->addWidget(labelLogo);
	layoutLogo->addStretch();
	layoutLogo->addWidget(labelTitle);
	layoutMain->addLayout(layoutLogo);
	layoutMain->addStretch();
	layoutMain->addWidget(labelCopy);

	// Special Thanks area.
	QFrame *lineTop     = new QFrame(this);
	QFrame *lineBottom  = new QFrame(this);
	QLabel *labelThanks = new QLabel(
		// Yeah I know it's a fake list, but a HTML
		// list weirds out at different font sizes.
		"<p style=\"white-space: pre-wrap\">\n"
			"<b>"+tr("Special Thanks To:")+"</b>\n"
			"  &bull; QBasicer\n"
			"  &bull; Risen\n"
			"  &bull; NeuralStunner\n"
			"  &bull; Enjay\n"
			"  &bull; "+tr("The ZDoom forumers")+"\n"
			"  &bull; "+tr("The non-idle #zdoom users")+" ;)\n"
		"</p>", this);
	if( !lineTop || !lineBottom || !labelThanks )
		throw "Couldn't create the thanks label!";
	lineTop->setFrameStyle(QFrame::HLine);
	lineBottom->setFrameStyle(QFrame::HLine);
	layoutMain->addWidget(lineTop);
	layoutMain->addWidget(labelThanks);
	layoutMain->addWidget(lineBottom);

	// Create the build info and button down at the bottom.
	QHBoxLayout *layoutButton = new QHBoxLayout();
	QLabel      *labelInfo    = new QLabel(ZDL_TIMESTAMP"\n"ZDL_PLATFORM, this);
	QPushButton *buttonClose  = new QPushButton(tr("Close"), this);
	// Make sure all the widgets got created properly.
	if( !layoutButton || !labelInfo || !buttonClose )
		throw "Couldn't create the info/button area!";
	layoutButton->addWidget(labelInfo);
	layoutButton->addStretch();
	layoutButton->addWidget(buttonClose);
	layoutMain->addLayout(layoutButton);

	// Connect the button signals.
	connect(buttonClose, SIGNAL(clicked()), this, SLOT(accept()));

	// Prep the window and show it.
	this->layout()->setSizeConstraint( QLayout::SetFixedSize ); // No resizing.
	this->show(); // Show before moving to update the internal window size.
}

