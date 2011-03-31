/**
* @file ZDLMainWindow.h
* ZDLMainWindow class header.
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
#ifndef ZDLMAINWINDOW_H
#define ZDLMAINWINDOW_H

#include "ZDLTabMain.h"
#include "ZDLTabMulti.h"

#include "ZDLAboutWindow.h"

// Qt Stuff.
#include <QDebug>
#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QTabWidget>
#include <QtGui/QPushButton>
#include <QtGui/QMenu>

// Needed for Centering (Boooo!)
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>

/**
* @class ZDLMainWindow
* Main user interface class.
*
* Yes, I know it's not based on QMainWindow. When it needs a menubar, statusbar,
* or dock, I'll think about changing it. :P
*/
class ZDLMainWindow : public QWidget {
	Q_OBJECT

	public:
	// Public Functions.
		static ZDLMainWindow* newInstance( QString windowTitle, QWidget *parentWidget = NULL );

	protected slots:
	// Buttons.
		void onLaunchClicked( );
		void onExitClicked( );

	// Menu Items.
		void onMenuShowCommand( );
		void onMenuSavePreset( );
		void onMenuLoadPreset( );
		void onMenuConfigWindow( );
		void onMenuAboutWindow( );

	protected:
	// Protected Windows.
		ZDLAboutWindow *aboutWindow; ///< About window.

	// Protected Widgets.
		ZDLTab *tabMain;  ///< General Tab
		ZDLTab *tabMulti; ///< Multiplayer Tab

	// Protected Functions.
		ZDLMainWindow( QString windowTitle, QWidget *parentWidget );
};

#endif // ZDLMAINWINDOW_H

