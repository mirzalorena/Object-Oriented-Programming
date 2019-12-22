#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamOOP.h"
#include "Controller.h"


class ExamOOP : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	ExamOOP(Controller & controller, Ethnologist ethnologist,QWidget *parent = Q_NULLPTR);

	void populate();
	void update()override { this->populate(); }

private:
	Ui::ExamOOPClass ui;
	Controller & controller;
	Ethnologist ethnologist;

private slots:
	void handleAddButton();
	void handleUpdateButton();

};
