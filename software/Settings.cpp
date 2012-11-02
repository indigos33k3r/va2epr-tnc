/*
 * va2epr-tnc software - terminal node controller software for va2epr-tnc
 * Copyright (C) 2012 Thomas Cort <va2epr@rac.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* GLOBAL INCLUDES */

#include <QtGui>

/* LOCAL INCLUDES */

#include "Settings.h"
#include "main.h"

Settings::Settings(QWidget *parent) : QWidget(parent) {

	_layout = new QVBoxLayout();
	_buttonLayout = new QHBoxLayout();
	_formLayout = new QFormLayout();

	// TODO add tooltips

	_tx_delayLabel = new QLabel();
	_tx_delayLabel->setText(tr("TX Delay"));
	_tx_delay = new QLineEdit();
	_formLayout->addRow(_tx_delayLabel, _tx_delay);

	_pLabel = new QLabel();
	_pLabel->setText(tr("p"));
	_p = new QLineEdit();
	_formLayout->addRow(_pLabel, _p);

	_slot_timeLabel = new QLabel();
	_slot_timeLabel->setText(tr("Slot Time"));
	_slot_time = new QLineEdit();
	_formLayout->addRow(_slot_timeLabel, _slot_time);

	_tx_tailLabel = new QLabel();
	_tx_tailLabel->setText(tr("TX Tail"));
	_tx_tail = new QLineEdit();
	_formLayout->addRow(_tx_tailLabel, _tx_tail);

	_full_duplexLabel = new QLabel();
	_full_duplexLabel->setText(tr("Full Duplex"));
	_full_duplex = new QCheckBox();
	_formLayout->addRow(_full_duplexLabel, _full_duplex);

	_callsignLabel = new QLabel();
	_callsignLabel->setText(tr("Callsign"));
	_callsign = new QLineEdit();
	_formLayout->addRow(_callsignLabel, _callsign);

	_layout->addLayout(_formLayout);

	_program = new QPushButton();
	_program->setText(tr("Program Device"));
	connect(_program, SIGNAL(clicked()), this, SLOT(doProgram()));
	_buttonLayout->addWidget(_program);

	_read = new QPushButton();
	_read->setText(tr("Read Device"));
	connect(_read, SIGNAL(clicked()), this, SLOT(doRead()));
	_buttonLayout->addWidget(_read);

	_defaults = new QPushButton();
	_defaults->setText(tr("Load Defaults"));
	connect(_defaults, SIGNAL(clicked()), this, SLOT(doDefaults()));
	_buttonLayout->addWidget(_defaults);

	_layout->addLayout(_buttonLayout);

	setLayout(_layout);
}

void Settings::doProgram(void) {

	// TODO do some data validation
}

void Settings::doRead(void) {

}

void Settings::doDefaults(void) {

	_tx_delay->setText(tr("50"));
	_p->setText(tr("63"));
	_slot_time->setText(tr("10"));
	_tx_tail->setText(tr("50"));
	_full_duplex->setCheckState(Qt::Unchecked);
	_callsign->setText(tr("VA2EPR"));
}
