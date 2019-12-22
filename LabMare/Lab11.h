#pragma once
#include <QtWidgets/QMainWindow>
#include <QSortFilterProxyModel>
#include "ui_Lab11.h"
#include "ui_userMode.h"
#include "Controller.h"
#include "Evidence.h"
#include "EvidenceTableModel.h"
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>
#include <qshortcut.h>

#include <vector>
#include <algorithm>
#include "Utils.h"
#include "EvidenceModel.h"
#include "userView.h"

class Lab11 : public QMainWindow
{
	Q_OBJECT

public:
	Lab11(Controller &controller,QWidget *parent = Q_NULLPTR);
	void populate();
	void populateUser();

private:
	Ui::Lab11Class ui;
	Controller &controller;
	EvidenceModel *model;
	userView *view;

private slots:
	void handleAddButton();
	void handleDeleteButton();
	void handleUpdateButton();
	void handleSaveButton();
	void handleNextButton();
	void handleFilterButton();
	void handleUndoButton();
	void handleRedoButton();
	void handelMyListButton();


};
