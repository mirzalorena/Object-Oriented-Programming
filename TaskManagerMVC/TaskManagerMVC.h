#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerMVC.h"
#include "TaskModel.h"
#include "Controller.h"


class TaskManagerMVC : public QMainWindow
{
	Q_OBJECT

public:
	TaskManagerMVC(Controller & controller,
		TaskModel * model,
		Programmer programmer,QWidget *parent = Q_NULLPTR);

	void populate();

private:
	Ui::TaskManagerMVCClass ui;
	TaskModel *model;
	Controller & controller;
	Programmer programmer;

private slots:
	void handleAddButton();
	void handleRemoveButton();
		void handleStart();
		void handleDone();


};
