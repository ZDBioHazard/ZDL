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
* @param  windowTitle  The new window's title.
*
* @return New ZDLMainWindow object on success, NULL on failure.
*/
ZDLMainWindow* ZDLMainWindow::newInstance( QString windowTitle ){
	qDebug() << "ZDLMainWindow::newInstance: Creating a new ZDLMainWindow instance.";
	try {
		ZDLMainWindow *newMainWindow = new ZDLMainWindow(windowTitle);
		return newMainWindow;
	} catch ( char const *except ){
		qCritical() << "ZDLMainWindow::newInstance: Caught exception:" << except;
		return NULL;
	}
	qCritical() << "ZDLMainWindow::newInstance: Something weird hapened!";
	return NULL; // Should never get here.
}

/**
* Constructor for ZDLMainWindow.
*
* @param  windowTitle  The new window's title.
*/
ZDLMainWindow::ZDLMainWindow( QString windowTitle ) : QWidget( ){
	this->setWindowTitle(windowTitle);

	// Set up the main layout.
	QVBoxLayout *layoutMain = new QVBoxLayout();
	layoutMain->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutMain);

	// Set-up the tab group.
	tabsMain = new QTabWidget(this);
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
	       this->buttonExit    = new QPushButton("Exit", this);
	       this->buttonZDL     = new QPushButton("ZDL", this);
	       this->buttonLaunch  = new QPushButton("Launch", this);
	// Make sure all the widgets got created properly.
	if( !layoutButtons   || !this->buttonExit   ||
	    !this->buttonZDL || !this->buttonLaunch )
		throw "Couldn't create the buttons!";
	// Aaand add them to the layout.
	layoutButtons->addWidget(buttonExit);
	layoutButtons->addWidget(buttonZDL);
	layoutButtons->addStretch();
	layoutButtons->addWidget(buttonLaunch);
	layoutMain->addLayout(layoutButtons);

	// Create the menu attached to the ZDL button.
	 this->menuZDL   = new QMenu("ZDL", this->buttonZDL);
	QMenu *menuReset = new QMenu("Reset Tab", this->buttonZDL);
	if( !this->menuZDL || !menuReset )
		throw "Couldn't create the ZDL button menus!";
	this->menuZDL->addAction("Show &Command Line");
		// TODO: This should iterate through all the tabs.
		menuReset->addAction("&Reset All Tabs");
		menuReset->addSeparator();
		menuReset->addAction("Reset "+tabMain->getTabLabel()+" Tab");
		menuReset->addAction("Reset "+tabMulti->getTabLabel()+" Tab");
		this->menuZDL->addMenu(menuReset);
	this->menuZDL->addSeparator();
	this->menuZDL->addAction("&Load Preset");
	this->menuZDL->addAction("&Save Preset");
	this->menuZDL->addSeparator();
	this->menuZDL->addAction("&Preferences");
	this->menuZDL->addAction("&About ZDL");
	this->buttonZDL->setMenu(menuZDL);

	// Well now, wasn't that fun? Time to prep the window and show it.
	// TODO: The window position and size should be pulled from the config.
	this->resize(1, 1); // As small as possible.
	this->show(); // Show before moving to update the internal window size.
	// Center the window on the screen.
	QRect rectDesktop = QApplication::desktop()->screenGeometry(this);
	this->move(rectDesktop.center()-this->rect().center());
}

