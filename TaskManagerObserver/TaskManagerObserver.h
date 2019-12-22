#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerObserver.h"
#include "Controller.h"
#include "Observer.h"

class TaskManagerObserver : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	TaskManagerObserver(Controller & controller,Programmer programmer,QWidget *parent = Q_NULLPTR);

	void populateList();
	void update()override { this->populateList(); }

private:
	Ui::TaskManagerObserverClass ui;
	Controller & controller;
	Programmer programmer;

private slots:
	void handleAddButton();
	void handleStart();
	void handleDone();
	void handleRemove();

};
