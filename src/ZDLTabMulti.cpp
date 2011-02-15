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

	// Game Mode.
	QLabelLayout *labelGameMode = new QLabelLayout("Game Mode", this);
			this->comboGameMode = new QComboBox(this);
	if( !labelGameMode || !this->comboGameMode ){
		// TODO: Error report here.
		return; // Bail out.
	}
	// TODO: I don't like this list being here for some reason.
	QStringList strGameModes;
	strGameModes << "Single-Player"           << "Multiplayer: Join"
	             << "Multiplayer: Host Co-Op" << "Multiplayer: Host Deathmatch";
	this->comboGameMode->addItems(strGameModes);
	labelGameMode->addWidget(this->comboGameMode);
	layoutTab->addLayout(labelGameMode, 0, 0, 1, 2);

	// Players.
	QLabelLayout *labelPlayers = new QLabelLayout("Players", this);
			this->spinPlayers  = new QSpinBox(this);
	if( !labelPlayers || !this->spinPlayers ){
		// TODO: Error report here.
		return; // Bail out.
	}
	labelPlayers->addWidget(this->spinPlayers);
	layoutTab->addLayout(labelPlayers, 0, 2, 1, 1);

	// TODO: Host Name
	// TODO: Port
	// TODO: Frag Limit
	// TODO: Time Limit
	// TODO: DUP

	// Extratic.
	this->checkExtratic = new QCheckBox("Extratic", this);
	if( !checkExtratic ){
		// TODO: Error report here.
		return; // Bail out.
	}
	layoutTab->addWidget(checkExtratic, 3, 0, 1, 3);

	// Push everything up to the top of the tab.
	QSpacerItem *spacerMulti = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	if( !spacerMulti ){
		// TODO: Error report here.
		return; // Bail out.
	}
	layoutTab->addItem(spacerMulti, 4, 0, 1, 3);

	// Looks like we're done here. ...Finally.
	this->initOK = TRUE; // Class is good to go!
}

