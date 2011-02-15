/**
* @file ZDLTabMulti.h
* ZDLTabMulti class header.
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
#ifndef ZDLTABMULTI_H
#define ZDLTABMULTI_H

#include "ZDLTab.h"
#include <QtGui/QVBoxLayout>

/**
* @class ZDLTabMulti
* Main user interface class.
*/
class ZDLTabMulti : public ZDLTab {
	public:
	// Public Functions.
		static ZDLTabMulti* newInstance( QWidget *parentWidget );

	protected:
	// Protected Functions.
		ZDLTabMulti( QWidget *parentWidget );
};

#endif // ZDLTABMULTI_H

