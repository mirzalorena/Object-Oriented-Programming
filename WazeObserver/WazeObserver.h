#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WazeObserver.h"
#include "Controller.h"
#include "Observer.h"

class WazeObserver : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	WazeObserver(Controller&controller, Driver driver,QWidget *parent = Q_NULLPTR);

	void populate();
	void update()override { this->populate(); }

private:
	Ui::WazeObserverClass ui;
	Controller&controller;
	Driver driver;

private slots:
	void handleAddButton();
	void handleValidate();

};
