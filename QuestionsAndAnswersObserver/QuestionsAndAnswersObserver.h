#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QuestionsAndAnswersObserver.h"
#include "Controller.h"
#include "Observer.h"

class QuestionsAndAnswersObserver : public QMainWindow,public Observer

{
	Q_OBJECT

public:
	QuestionsAndAnswersObserver(Controller& controller,User user,QWidget *parent = Q_NULLPTR);

	void populateList();
	void populateAnswers(int qid);
	void update()override { this->populateList(); }

private:
	Ui::QuestionsAndAnswersObserverClass ui;
	Controller & controller;
	User user;

private slots:
	void handleSearchButton();
	void handleAddButton();
	void handleSelect(QListWidgetItem* h);
	void handleAddAnswer();

};
