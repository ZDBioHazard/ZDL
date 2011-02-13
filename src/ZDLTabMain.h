/**
* @file ZDLTabMain.h
* ZDLTabMain class header.
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
#ifndef ZDLTABMAIN_H
#define ZDLTABMAIN_H

#include "ZDLTab.h"

/**
* @class ZDLTabMain
* Main user interface class.
*/
class ZDLTabMain : public ZDLTab {
	public:
	// Public Functions.
		static ZDLTabMain* newInstance( QWidget *parentWidget );

	protected:
	// Protected Functions.
		ZDLTabMain( QWidget *parentWidget );
};

#endif // ZDLTABMAIN_H

