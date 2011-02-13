/**
* @file QLabelLayout.h
* QLabelLayout class header.
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
#ifndef QLABELLAYOUT_H
#define QLABELLAYOUT_H

#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>

/**
* @class QLabelLayout
* Simple widget for labeling other widgets.
*
* This class is a widget that saves the trouble of making a box and a label to
* put a label on a widget.
*/
class QLabelLayout : public QVBoxLayout {
	public:
	// Public Functions.
		/**
		* Constructor for QLabelLayout.
		*
		* @param  widgetLabel  String to use for the label widget.
		* @param  parentWidget  Parent widget to assign to the label widget.
		*/
		QLabelLayout( QString widgetLabel, QWidget *parentWidget ) : QVBoxLayout(){
			QLabel *labelLabel = new QLabel(widgetLabel, parentWidget);
			this->setSpacing(0);
			this->addWidget(labelLabel);
		}
};

#endif // QLABELLAYOUT_H

