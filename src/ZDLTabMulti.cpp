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
* @param  parentWidget  Parent widget to assign this widget to.
*
* @return New ZDLTabMulti object on success, NULL on failure.
*/
ZDLTabMulti* ZDLTabMulti::newInstance( QWidget *parentWidget ){
	qDebug() << "ZDLTabMulti::newInstance: Creating a new ZDLTab instance.";
	try {
		ZDLTabMulti *newTab = new ZDLTabMulti(parentWidget);
		return newTab;
	} catch ( char const *except ){
		qCritical() << "ZDLTabMulti::newInstance: Caught exception:" << except;
		return NULL;
	}
	qCritical() << "ZDLTabMulti::newInstance: Something weird hapened!";
	return NULL; // Should never get here.
}

/**
* Constructor for ZDLTabMulti.
*
* @param  parentWidget  Parent widget to assign this widget to.
*/
ZDLTabMulti::ZDLTabMulti( QWidget *parentWidget ) : ZDLTab( parentWidget ){
	// Set the tab name.
	this->tabLabel = tr("Multiplayer");

	//
	// NOTE: The indentation in this function sort-of
	//       illustrates how the widgets are nested.
	//

	// Set up the main layout.
	QGridLayout *layoutTab = new QGridLayout();
	layoutTab->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutTab);

	// Game Mode / Players.
	QLabelLayout *labelGameMode = new QLabelLayout(tr("Game Mode"), this);
	        this->comboGameMode = new QComboBox(this);
	QLabelLayout *labelPlayers  = new QLabelLayout(tr("Players"), this);
	        this->spinPlayers   = new QSpinBox(this);
	if( !labelGameMode || !this->comboGameMode ||
	    !labelPlayers  || !this->spinPlayers   )
		throw "Couldn't create the Mode/Players widgets!";
	// TODO: I don't like this list being here for some reason.
	QStringList strGameModes;
	strGameModes << tr("Single-Player")
	             << tr("Multi-Player: Co-Op") << tr("Multi-Player: Deathmatch");
	this->comboGameMode->addItems(strGameModes);
	// TODO: This should be set by the port config eventually.
	this->spinPlayers->setRange(0, 8);
	this->spinPlayers->setSpecialValueText(tr("Joining"));
	labelGameMode->addWidget(this->comboGameMode);
	layoutTab->addLayout(labelGameMode, 0, 0, 1, 2);
	labelPlayers->addWidget(this->spinPlayers);
	layoutTab->addLayout(labelPlayers, 0, 2, 1, 1);

	// Server Hostname/IP / Server Port.
	QLabelLayout *labelHost = new QLabelLayout(tr("Server Hostname / IP"), this);
	        this->editHost  = new QLineEdit(this);
	QLabelLayout *labelPort = new QLabelLayout(tr("Port"), this);
	        this->spinPort  = new QSpinBox(this);
	if( !labelHost || !this->editHost ||
	    !labelPort || !this->spinPort )
		throw "Couldn't create the Host/Port widgets!";
	this->spinPort->setRange(MIN_PORT, MAX_PORT);
	this->spinPort->setValue(DEFAULT_PORT);
	labelHost->addWidget(this->editHost);
	layoutTab->addLayout(labelHost, 1, 0, 1, 2);
	labelPort->addWidget(this->spinPort);
	layoutTab->addLayout(labelPort, 1, 2, 1, 1);

	// Frag Limit / Time Limit.
	QLabelLayout *labelFragLimit = new QLabelLayout(tr("Frag Limit"), this);
	        this->spinFragLimit  = new QSpinBox(this);
	QLabelLayout *labelTimeLimit = new QLabelLayout(tr("Time Limit"), this);
	        this->spinTimeLimit  = new QSpinBox(this);
	if( !labelFragLimit || !this->spinFragLimit ||
	    !labelTimeLimit || !this->spinTimeLimit )
		throw "Couldn't create the Frag/Time limit widgets!";
	spinFragLimit->setRange(0, MAX_FRAGS);
	labelFragLimit->addWidget(this->spinFragLimit);
	layoutTab->addLayout(labelFragLimit, 0, 3, 1, 1);
	spinFragLimit->setRange(0, MAX_TIME);
	labelTimeLimit->addWidget(this->spinTimeLimit);
	layoutTab->addLayout(labelTimeLimit, 1, 3, 1, 1);

	// Magic / Enable Cheats.
	this->checkMagic  = new QCheckBox(tr("Magically Fix Everything"), this);
	this->checkCheats = new QCheckBox(tr("Enable Cheats"), this);
	if( !this->checkMagic || !this->checkCheats )
		throw "Couldn't create the Checkboxes!";
	layoutTab->addWidget(this->checkMagic, 2, 0, 1, 2);
	layoutTab->addWidget(this->checkCheats,  2, 2, 1, 2);

	// Push everything up to the top of the tab.
	// Unfortunately a full-blown QSpacerItem has to be used in QGridLayouts
	// instead of just addStretch(). :(
	QSpacerItem *spacerMulti = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	if( !spacerMulti )
		throw "Couldn't create the Spacer!";
	layoutTab->addItem(spacerMulti, 4, 0, 1, 3);
}

