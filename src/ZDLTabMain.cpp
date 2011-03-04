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
* @param  parentWidget  Parent widget to assign this widget to.
*
* @return New ZDLTabMain object on success, NULL on failure.
*/
ZDLTabMain* ZDLTabMain::newInstance( QWidget *parentWidget ){
	qDebug() << "ZDLTabMain: Creating a new instance.";
	ZDLTabMain *newTab = new ZDLTabMain(parentWidget);
	if( newTab->getInitOK() == FALSE ){
		qCritical() << "ZDLTabMain: Couldn't create a new instance!";
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
	QLabelLayout *labelFiles         = new QLabelLayout("External Files", this);
	        this->listFiles          = new QListWidget(this);
	QHBoxLayout  *layoutFilesButtons = new QHBoxLayout();
	        this->buttonFilesAdd     = new QPushButton("Add", this);
	        this->buttonFilesRemove  = new QPushButton("Remove", this);
	if( !layoutFiles          || !labelFiles              ||
	    !layoutFilesButtons   || !this->listFiles         ||
	    !this->buttonFilesAdd || !this->buttonFilesRemove ){
			qCritical() << "ZDLTabMain: Couldn't create the External Files list!";
		return; // Bail out.
	}
	layoutFiles->addLayout(labelFiles);
	labelFiles->addWidget(this->listFiles);
	layoutFiles->addLayout(layoutFilesButtons);
	layoutFilesButtons->addWidget(this->buttonFilesAdd);
	layoutFilesButtons->addStretch();
	layoutFilesButtons->addWidget(this->buttonFilesRemove);
	layoutColumns->addLayout(layoutFiles);

	// Right Column
	QVBoxLayout *layoutRightColumn = new QVBoxLayout();
	layoutColumns->addLayout(layoutRightColumn);

		// Engine list.
		QLabelLayout *labelEngines = new QLabelLayout("Game Engine", this);
			    this->comboEngines = new QComboBox(this);
		if( !labelEngines || !this->comboEngines ){
			qCritical() << "ZDLTabMain: Couldn't create the Engines list!";
			return; // Bail out.
		}
		labelEngines->addWidget(this->comboEngines);
		layoutRightColumn->addLayout(labelEngines);

		// IWAD list.
		QLabelLayout *labelIWADs = new QLabelLayout("Game IWAD", this);
			    this->listIWADs  = new QListWidget(this);
		if( !labelIWADs || !this->listIWADs ){
			qCritical() << "ZDLTabMain: Couldn't create the IWAD list!";
			return; // Bail out.
		}
		labelIWADs->addWidget(this->listIWADs);
		layoutRightColumn->addLayout(labelIWADs);

		// Warp/Skill box.
		QHBoxLayout *layoutWarpSkill = new QHBoxLayout();
		layoutRightColumn->addLayout(layoutWarpSkill);

			// Warp box.
			QLabelLayout *labelWarp = new QLabelLayout("Warp to Map", this);
					this->editWarp  = new QLineEdit(this);
			if( !labelWarp || !this->editWarp ){
				qCritical() << "ZDLTabMain: Couldn't create the Warp box!";
				return; // Bail out.
			}
			editWarp->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
			labelWarp->addWidget(this->editWarp);
			layoutWarpSkill->addLayout(labelWarp);

			// Skill box.
			QLabelLayout *labelSkill = new QLabelLayout("Skill Level", this);
					this->comboSkill = new QComboBox(this);
			if( !labelSkill || !this->comboSkill ){
				qCritical() << "ZDLTabMain: Couldn't create the Skill box!";
				return; // Bail out.
			}
			// TODO: I don't like this list being here for some reason.
			QStringList strSkills;
			strSkills << "Very Easy" << "Easy" << "Normal" << "Hard" << "Stupid-Hard";
			this->comboSkill->addItems(strSkills);
			this->comboSkill->setCurrentIndex(SKILL_NORMAL);
			labelSkill->addWidget(this->comboSkill);
			layoutWarpSkill->addLayout(labelSkill);

	// Extra Args box.
	QLabelLayout *labelExtraArgs = new QLabelLayout("Extra Command-Line Arguments", this);
	        this->editExtraArgs  = new QLineEdit(this);
	if( !labelExtraArgs || !this->editExtraArgs ){
		qCritical() << "ZDLTabMain: Couldn't create the Extra Args box!";
		return; // Bail out.
	}
	labelExtraArgs->addWidget(this->editExtraArgs);
	layoutTab->addLayout(labelExtraArgs);

	// Looks like we're done here. ...Finally.
	this->initOK = TRUE; // Class is good to go!
}

