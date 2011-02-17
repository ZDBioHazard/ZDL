/**
* @file ZDLTab.h
* ZDLTab class header.
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
#ifndef ZDLTAB_H
#define ZDLTAB_H

// Qt Stuff.
#include <QtGui/QWidget>

/**
* @class ZDLTab
* Abstract user interface class.
*/
class ZDLTab : public QWidget {
	public:
	// Public Functions.
		static ZDLTab* newInstance( QWidget *parentWidget );
		       QString getTabLabel( );

	protected:
	// Protected Variables.
		bool    initOK;   ///< Object initialization status.
		QString tabLabel; ///< Text to be displayed on the tab.

	// Protected Functions.
		bool getInitOK( );
		        ZDLTab( QWidget *parentWidget );
};

#endif // ZDLTAB_H

