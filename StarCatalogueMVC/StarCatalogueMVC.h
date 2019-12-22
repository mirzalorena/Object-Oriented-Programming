#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StarCatalogueMVC.h"
#include "StarModel.h"
#include "Controller.h"


class StarCatalogueMVC : public QMainWindow
{
	Q_OBJECT

public:
	StarCatalogueMVC(Controller & controller,
		StarModel * model,
		Astronomer astronomer,QWidget *parent = Q_NULLPTR);

	void populate();

private:
	Ui::StarCatalogueMVCClass ui;
	StarModel *model;
	Controller & controller;
	Astronomer astronomer;

private slots:
	void handleAddButton();
	void handleSearchButton();

};
