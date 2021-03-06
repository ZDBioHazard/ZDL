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

///////////////////////////////////////////////////////////////////////////////
// Public Functions
///////////////////////////////////////////////////////////////////////////////

/**
* Instance generator for ZDLTabMain.
*
* @param  parentWidget  Parent widget to assign this widget to.
*
* @return New ZDLTabMain object on success, NULL on failure.
*/
ZDLTabMain* ZDLTabMain::newInstance( QWidget *parentWidget ){
	qDebug() << "ZDLTabMain::newInstance: Creating a new ZDLTab instance.";
	try {
		ZDLTabMain *newTab = new ZDLTabMain(parentWidget);
		return newTab;
	} catch ( char const *except ){
		qCritical() << "ZDLTabMain::newInstance: Caught exception:" << except;
		return NULL;
	}
	qCritical() << "ZDLTabMain::newInstance: Something weird hapened!";
	return NULL; // Should never get here.
}

///////////////////////////////////////////////////////////////////////////////
// Protected Slots
///////////////////////////////////////////////////////////////////////////////

/**
* Add files to the files list.
*/
void ZDLTabMain::onFilesAddClicked( ){
	qWarning() << "ZDLTabMain: FilesAdd button clicked. (Stub)";
}

/**
* Remove files from the files list.
*/
void ZDLTabMain::onFilesRemoveClicked( ){
	qWarning() << "ZDLTabMain: FilesRemove button clicked. (Stub)";
}

///////////////////////////////////////////////////////////////////////////////
// Protected Functions
///////////////////////////////////////////////////////////////////////////////

/**
* Constructor for ZDLTabMain.
*
* @param  parentWidget  Parent widget to assign this widget to.
*/
ZDLTabMain::ZDLTabMain( QWidget *parentWidget ) : ZDLTab( parentWidget ){
	// This tab be called Jimmy!
	this->tabLabel = tr("General");

	//
	// NOTE: The indentation in this function sort-of
	//       illustrates how the widgets are nested.
	//

	// Set up the main layout.
	QVBoxLayout *layoutTab = new QVBoxLayout();
	layoutTab->setContentsMargins(6, 6, 6, 6); // The usual widget spacing.
	this->setLayout(layoutTab);

	// Set-up the main columns.
	// TODO: It would be cool if this could be a QSplitter, but QSplitter
	//       doesn't seem to support adding layouts, only widgets.
	QHBoxLayout *layoutColumns = new QHBoxLayout();
	layoutTab->addLayout(layoutColumns);

	// Left Column.
	// External Files list.
	QVBoxLayout  *layoutFiles        = new QVBoxLayout();
	QLabelLayout *labelFiles         = new QLabelLayout(tr("External Files"), this);
	        this->listFiles          = new QListWidget(this);
	QHBoxLayout  *layoutFilesButtons = new QHBoxLayout();
	QPushButton  *buttonFilesAdd     = new QPushButton(tr("Add"), this);
	QPushButton  *buttonFilesRemove  = new QPushButton(tr("Remove"), this);
	if( !layoutFiles        || !labelFiles        ||
	    !layoutFilesButtons || !this->listFiles   ||
	    !buttonFilesAdd     || !buttonFilesRemove )
		throw "Couldn't create the External Files list!";
	layoutFiles->addLayout(labelFiles);
	labelFiles->addWidget(this->listFiles);
	layoutFiles->addLayout(layoutFilesButtons);
	layoutFilesButtons->addWidget(buttonFilesAdd);
	layoutFilesButtons->addStretch();
	layoutFilesButtons->addWidget(buttonFilesRemove);
	layoutColumns->addLayout(layoutFiles);

	// Connect the button signals.
	connect(buttonFilesAdd,    SIGNAL(clicked()), this, SLOT(onFilesAddClicked()));
	connect(buttonFilesRemove, SIGNAL(clicked()), this, SLOT(onFilesRemoveClicked()));

	// Right Column
	QVBoxLayout *layoutRightColumn = new QVBoxLayout();
	layoutColumns->addLayout(layoutRightColumn);

		// Engine list.
		QLabelLayout *labelEngines = new QLabelLayout(tr("Game Engine"), this);
		        this->comboEngines = new QComboBox(this);
		if( !labelEngines || !this->comboEngines )
			throw "Couldn't create the Engines list!";
		labelEngines->addWidget(this->comboEngines);
		layoutRightColumn->addLayout(labelEngines);

		// IWAD list.
		QLabelLayout *labelIWADs = new QLabelLayout(tr("Game IWAD"), this);
		        this->listIWADs  = new QListWidget(this);
		if( !labelIWADs || !this->listIWADs )
			throw "Couldn't create the IWAD list!";
		labelIWADs->addWidget(this->listIWADs);
		layoutRightColumn->addLayout(labelIWADs);

		// Warp/Skill box.
		QHBoxLayout *layoutWarpSkill = new QHBoxLayout();
		layoutRightColumn->addLayout(layoutWarpSkill);

			// Warp box.
			QLabelLayout *labelWarp = new QLabelLayout(tr("Warp to Map"), this);
			        this->editWarp  = new QLineEdit(this);
			if( !labelWarp || !this->editWarp )
				throw "Couldn't create the Warp box!";
			editWarp->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
			labelWarp->addWidget(this->editWarp);
			layoutWarpSkill->addLayout(labelWarp);

			// Skill box.
			QLabelLayout *labelSkill = new QLabelLayout(tr("Skill Level"), this);
			        this->comboSkill = new QComboBox(this);
			if( !labelSkill || !this->comboSkill )
				throw "Couldn't create the Skill box!";
			// TODO: I don't like this list being here for some reason.
			QStringList strSkills;
			strSkills << tr("Very Easy") << tr("Easy") << tr("Normal")
			          << tr("Hard") << tr("Very Hard");
			this->comboSkill->addItems(strSkills);
			this->comboSkill->setCurrentIndex(SKILL_NORMAL);
			labelSkill->addWidget(this->comboSkill);
			layoutWarpSkill->addLayout(labelSkill);

	// Extra Args box.
	QLabelLayout *labelExtraArgs = new QLabelLayout(tr("Extra Command-Line Arguments"), this);
	        this->editExtraArgs  = new QLineEdit(this);
	if( !labelExtraArgs || !this->editExtraArgs )
		throw "Couldn't create the Extra Args box!";
	labelExtraArgs->addWidget(this->editExtraArgs);
	layoutTab->addLayout(labelExtraArgs);
}

