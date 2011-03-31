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

///////////////////////////////////////////////////////////////////////////////
// Public Functions
///////////////////////////////////////////////////////////////////////////////

/**
* Instance generator for ZDLMainWindow.
*
* @param  windowTitle  The new window's title.
*
* @return New ZDLMainWindow object on success, NULL on failure.
*/
ZDLMainWindow* ZDLMainWindow::newInstance( QWidget *parentWidget ){
	qDebug() << "ZDLMainWindow::newInstance: Creating a new ZDLMainWindow instance.";
	try {
		ZDLMainWindow *newMainWindow = new ZDLMainWindow(parentWidget);
		return newMainWindow;
	} catch ( char const *except ){
		qCritical() << "ZDLMainWindow::newInstance: Caught exception:" << except;
		return NULL;
	}
	qCritical() << "ZDLMainWindow::newInstance: Something weird hapened!";
	return NULL; // Should never get here.
}

///////////////////////////////////////////////////////////////////////////////
// Protected Slots
///////////////////////////////////////////////////////////////////////////////

/**
* This is what the whole application is about.
*/
void ZDLMainWindow::onLaunchClicked( ){
	qWarning() << "ZDLMainWindow: Launch button clicked. (Stub)";
}

/**
* Closes the ZDLMainWindow.
*/
void ZDLMainWindow::onExitClicked( ){
	qDebug() << "ZDLMainWindow: Exit button clicked.";
	// TODO: Remember to save everything!
	this->close();
}

/**
* Show the command line that will be run when "Launch" is pressed.
*/
void ZDLMainWindow::onMenuShowCommand( ){
	qWarning() << "ZDLMainWindow: Show Command menu item selected. (Stub)";
}

/**
* Save Preset file.
*/
void ZDLMainWindow::onMenuSavePreset( ){
	qWarning() << "ZDLMainWindow: Save Preset menu item selected. (Stub)";
}

/**
* Load Preset file.
*/
void ZDLMainWindow::onMenuLoadPreset( ){
	qWarning() << "ZDLMainWindow: Load Preset menu item selected. (Stub)";
}

/**
* Show the Configuration window.
*/
void ZDLMainWindow::onMenuConfigWindow( ){
	qWarning() << "ZDLMainWindow: Configuration menu item selected. (Stub)";
}

/**
* Show the About window.
*/
void ZDLMainWindow::onMenuAboutWindow( ){
	qDebug() << "ZDLMainWindow: About menu item selected.";

	// Create the About window instance if it doesn't exist yet.
	if( !this->aboutWindow ){
		this->aboutWindow = ZDLAboutWindow::newInstance(this);
		if( !this->aboutWindow ){ // Check if the object is okay.
			qCritical() << "ZDLMainWindow: Couldn't create the ZDLAboutWindow.";
			return; // Run before it's too late!
		}
	} else { // Show, Focus and Activate the window if it already exists.
		this->aboutWindow->show();
		this->aboutWindow->raise();
		this->aboutWindow->activateWindow();
	}
}

///////////////////////////////////////////////////////////////////////////////
// Protected Functions
///////////////////////////////////////////////////////////////////////////////

/**
* Constructor for ZDLMainWindow.
*
* @param  windowTitle  The new window's title.
*/
ZDLMainWindow::ZDLMainWindow( QWidget *parentWidget ) : QWidget( parentWidget ){
	// Set some window properties.
	this->setWindowTitle(ZDL_NAME" "ZDL_VERSION);
	this->setWindowIcon(QIcon(":/zdlicon"));

	// Initialize member variables that won't be used in this function.
	this->aboutWindow = NULL;

	// Set up the main layout.
	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutMain);

	// Set-up the tab group.
	QTabWidget *tabsMain = new QTabWidget(this);
	layoutMain->addWidget(tabsMain);

	// Create the interface tabs.
	// TODO: Eventually this should be some sort of iterator.
	this->tabMain  = ZDLTabMain::newInstance(this);
	this->tabMulti = ZDLTabMulti::newInstance(this);
	if( !this->tabMain || !this->tabMulti )
		throw "Couldn't create the interface tabs!";

	tabsMain->addTab(this->tabMain, this->tabMain->getTabLabel());
	tabsMain->addTab(this->tabMulti, this->tabMulti->getTabLabel());

	// Create the buttons down at the bottom.
	QHBoxLayout *layoutButtons = new QHBoxLayout();
	QPushButton *buttonExit    = new QPushButton(tr("Exit"), this);
	QPushButton *buttonZDL     = new QPushButton(ZDL_NAME, this);
	QPushButton *buttonLaunch  = new QPushButton(tr("Launch"), this);
	// Make sure all the widgets got created properly.
	if( !layoutButtons || !buttonExit   ||
	    !buttonZDL     || !buttonLaunch )
		throw "Couldn't create the buttons!";
	// Aaand add them to the layout.
	layoutButtons->addWidget(buttonExit);
	layoutButtons->addWidget(buttonZDL);
	layoutButtons->addStretch();
	layoutButtons->addWidget(buttonLaunch);
	layoutMain->addLayout(layoutButtons);

	// Connect the button signals.
	connect(buttonLaunch, SIGNAL(clicked()), this, SLOT(onLaunchClicked()));
	connect(buttonExit,   SIGNAL(clicked()), this, SLOT(onExitClicked()));

	// Create the menu attached to the ZDL button.
	// TODO: Include a tab reset menu.
	QMenu   *menuZDL         = new QMenu(ZDL_NAME, buttonZDL);
	QAction *actShowCommand  = new QAction(tr("S&how Command Line"), menuZDL);
	QAction *actSavePreset   = new QAction(tr("&Save Preset"), menuZDL);
	QAction *actLoadPreset   = new QAction(tr("&Load Preset"), menuZDL);
	QAction *actConfigWindow = new QAction(tr("&Configuration"), menuZDL);
	QAction *actAboutWindow  = new QAction(tr("&About")+" "ZDL_NAME, menuZDL);
	if( !menuZDL       || !actShowCommand  || !actSavePreset ||
	    !actLoadPreset || !actConfigWindow || !actAboutWindow )
		throw "Couldn't create the ZDL button menus!";
	menuZDL->addAction(actShowCommand);
	menuZDL->addSeparator();
	menuZDL->addAction(actSavePreset);
	menuZDL->addAction(actLoadPreset);
	menuZDL->addSeparator();
	menuZDL->addAction(actConfigWindow);
	menuZDL->addAction(actAboutWindow);
	buttonZDL->setMenu(menuZDL);

	// Connect the menu signals.
	connect(actShowCommand,  SIGNAL(triggered()), this, SLOT(onMenuShowCommand()));
	connect(actSavePreset,   SIGNAL(triggered()), this, SLOT(onMenuSavePreset()));
	connect(actLoadPreset,   SIGNAL(triggered()), this, SLOT(onMenuLoadPreset()));
	connect(actConfigWindow, SIGNAL(triggered()), this, SLOT(onMenuConfigWindow()));
	connect(actAboutWindow,  SIGNAL(triggered()), this, SLOT(onMenuAboutWindow()));

	// Well now, wasn't that fun? Time to prep the window and show it.
	// TODO: The window position and size should be pulled from the config.
	this->resize(1, 1); // As small as possible.
	this->show(); // Show before moving to update the internal window size.
	// Center the window on the screen.
	QRect rectDesktop = QApplication::desktop()->screenGeometry(this);
	this->move(rectDesktop.center()-this->rect().center());
}

