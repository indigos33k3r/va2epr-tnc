/*
 * va2epr-tnc software - terminal node controller software for va2epr-tnc
 * Copyright (C) 2012, 2013 Thomas Cort <va2epr@rac.ca>
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

/**
 * Settings widget for TNCs
 */
Settings::Settings(Console *console, QWidget *parent) : QWidget(parent) {

	qDebug() << "Settings::Settings() Enter";

	_layout = new QVBoxLayout();
	_buttonLayout = new QHBoxLayout();
	_formLayout = new QFormLayout();

	_tx_delayLabel = new QLabel();
	_tx_delayLabel->setText(tr("TX Delay"));
	_tx_delayLabel->setToolTip(tr("Transmitter Keyup Delay in 10ms Units (Default 50)"));
	_tx_delay = new QLineEdit();
	_tx_delay->setToolTip(tr("Transmitter Keyup Delay in 10ms Units (Default 50)"));
	_tx_delay->setText(tr("10"));
	_tx_delay_validator = new QIntValidator(0, 255);
	_tx_delay->setValidator(_tx_delay_validator);
	_formLayout->addRow(_tx_delayLabel, _tx_delay);

	_pLabel = new QLabel();
	_pLabel->setText(tr("p"));
	_pLabel->setToolTip(tr("Scaled Persistance Paramter (Default 63)"));
	_p = new QLineEdit();
	_p->setToolTip(tr("Scaled Persistance Paramter (Default 63)"));
	_p->setText(tr("63"));
	_p_validator = new QIntValidator(0, 255);
	_p->setValidator(_p_validator);
	_formLayout->addRow(_pLabel, _p);

	_slot_timeLabel = new QLabel();
	_slot_timeLabel->setText(tr("Slot Time"));
	_slot_timeLabel->setToolTip(tr("Slot Interval in 10ms Units (Default 10)"));
	_slot_time = new QLineEdit();
	_slot_time->setToolTip(tr("Slot Interval in 10ms Units (Default 10)"));
	_slot_time->setText(tr("10"));
	_slot_time_validator = new QIntValidator(0, 255);
	_slot_time->setValidator(_slot_time_validator);
	_formLayout->addRow(_slot_timeLabel, _slot_time);

	_tx_tailLabel = new QLabel();
	_tx_tailLabel->setText(tr("TX Tail"));
	_tx_tailLabel->setToolTip(tr("Time to hold after FCS in 10ms Units (Default 50)"));
	_tx_tail = new QLineEdit();
	_tx_tail->setToolTip(tr("Time to hold after FCS in 10ms Units (Default 50)"));
	_tx_tail->setText(tr("50"));
	_tx_tail_validator = new QIntValidator(0, 255);
	_tx_tail->setValidator(_tx_tail_validator);
	_formLayout->addRow(_tx_tailLabel, _tx_tail);

	_full_duplexLabel = new QLabel();
	_full_duplexLabel->setText(tr("Full Duplex"));
	_full_duplexLabel->setToolTip(tr("Unchecked = Half Duplex, Checked = Full Duplex (Default Half Duplex)"));
	_full_duplex = new QCheckBox();
	_full_duplex->setToolTip(tr("Unchecked = Half Duplex, Checked = Full Duplex (Default Half Duplex)"));
	_formLayout->addRow(_full_duplexLabel, _full_duplex);

	_callsignLabel = new QLabel();
	_callsignLabel->setText(tr("Callsign"));
	_callsignLabel->setToolTip(tr("Enter Your Callsign"));
	_callsign = new QLineEdit();
	_callsign->setToolTip(tr("Enter Your Callsign"));
	_callsign->setText(tr("XX0XXX"));
	QRegExp re("[A-Z0-9]{3,6}");
	_callsign_validator = new QRegExpValidator(re);
	_callsign->setValidator(_callsign_validator);
	_formLayout->addRow(_callsignLabel, _callsign);

	_layout->addLayout(_formLayout);

	_read = new QPushButton(QIcon(":/icons/actions/document-open.svg"), tr("Read Device"));
	_read->setToolTip(tr("Read configuration settings from the TNC (works on va2epr-tnc only)"));
	connect(_read, SIGNAL(clicked()), this, SLOT(doRead()));
	_buttonLayout->addWidget(_read);

	_program = new QPushButton(QIcon(":/icons/actions/document-save.svg"), tr("Program Device"));
	_program->setToolTip(tr("Write configuration settings to the TNC"));
	connect(_program, SIGNAL(clicked()), this, SLOT(doProgram()));
	_buttonLayout->addWidget(_program);

	_layout->addLayout(_buttonLayout);

	setLayout(_layout);

	_console = console;

	qDebug() << "Settings::Settings() Complete";
}

/**
 * Process clicks of the program device button.
 */
void Settings::doProgram(void) {

	qDebug() << "Settings::doProgram() Enter";

	qDebug() << "Settings::doProgram() Complete";
}

/**
 * Process clicks of the read device button.
 */
void Settings::doRead(void) {

	qDebug() << "Settings::doRead() Enter";

	// TODO do some data validation

	qDebug() << "Settings::doRead() Complete";

}
