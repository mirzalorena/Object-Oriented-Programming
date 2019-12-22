#pragma once

#include <QWidget>
#include "ui_userMode.h"

class userView :public QWidget
{
	Q_OBJECT

private:
	QAbstractItemModel* model;

public:
	userView(QAbstractItemModel* mode, QWidget *parent=Q_NULLPTR);
	userView();

private:
	Ui::userView ui;


};