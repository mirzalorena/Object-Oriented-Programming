#pragma once
#include "C:\Qt\5.12.3\msvc2017_64\include\QtWidgets\qwidget.h"
#include "Controller.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qflags.h>
#include <qlabel.h>
#include <iostream>
#include <vector>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>

class GUI :public QWidget
{
private:
	Controller controller;
	QListWidget *evidenceDataBase;
	QListWidget *userDataBase;
	QLineEdit *id, *measurement, *imageClarityLevel, *quantity, *photograph;
	QPushButton *addButton, *removeButton, *updateButton,*saveButton,*nextButton;
	void init();
	void populate();
	void populateUser();

public:
	//GUI();
	GUI(Controller controller);
	~GUI();

	void connectSignalsAndSlots();

private slots:
	void addEvidence();
	void deleteEvidence();
	void updateEvidence();
	void saveUser();
	void next();

};