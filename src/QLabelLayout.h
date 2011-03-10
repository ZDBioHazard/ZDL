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

// Qt Stuff.
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
			if( !(this->labelLabel = new QLabel(widgetLabel, parentWidget)) )
				throw "QLabelLayout: Couldn't create the Label!";
			this->setSpacing(0);
			this->addWidget(labelLabel);
		}

		/**
		* Gets the label text of the QLabelLayout.
		*
		* @return QString containing the label text.
		*/
		QString getLabelText( ){
			return this->labelLabel->text();
		}

		/**
		* Sets the label text of the QLabelLayout.
		*
		* @param  newText  New label text.
		*/
		void setLabelText( QString newText ){
			return this->labelLabel->setText(newText);
		}

	protected:
	// Protected Widgets.
		QLabel *labelLabel; ///< Widget Label.
};

#endif // QLABELLAYOUT_H

