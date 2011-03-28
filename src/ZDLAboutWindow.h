/**
* @file ZDLAboutWindow.h
* ZDLAboutWindow class header.
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
#ifndef ZDLABOUTWINDOW_H
#define ZDLABOUTWINDOW_H

// Qt Stuff.
#include <QDebug>
#include <QtGui/QDialog>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>

/**
* @class ZDLAboutWindow
* About window class.
*/
class ZDLAboutWindow : public QDialog {
	Q_OBJECT

	public:
	// Public Functions.
		static ZDLAboutWindow* newInstance( QWidget *parentWidget = NULL );

	protected:
	// Protected Functions.
		ZDLAboutWindow( QWidget *parentWidget );
};

#endif // ZDLABOUTWINDOW_H

