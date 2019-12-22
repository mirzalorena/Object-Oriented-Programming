#include "QuestionsAndAnswersObserver.h"
#include "qmessagebox.h"
#include <random>

QuestionsAndAnswersObserver::QuestionsAndAnswersObserver(Controller& controller, User user, QWidget *parent)
	: QMainWindow(parent),controller(controller),user(user)
{
	ui.setupUi(this);

	this->populateList();

	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(handleSearchButton()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));
	connect(ui.questionsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(handleSelect(QListWidgetItem*)));
	connect(ui.addAnsButton, SIGNAL(clicked()), this, SLOT(handleAddAnswer()));
}


bool cmp(Question a, Question b)
{
	return a.getAns() > b.getAns();
}

void QuestionsAndAnswersObserver::populateList()
{
	ui.questionsList->clear();
	std::vector<Question> list = controller.getQuestions();
	sort(list.begin(), list.end(), cmp);
	for (auto i : list)
	{
		std::string print = std::to_string(i.getId()) + "," + i.getText() + "," + i.getName();
		new QListWidgetItem(print.c_str(), ui.questionsList);
	}
}

void QuestionsAndAnswersObserver::populateAnswers(int qid)
{
	ui.answerList->clear();
	std::vector<Answer> list;
	list = controller.getAnswer(qid);
	for (auto i : list)
	{
		std::string print = std::to_string(i.getId()) + "," + std::to_string(i.getIdQ()) + "," + i.getText() + "," + i.getName() + "," + std::to_string(i.getVotes());
		new QListWidgetItem(print.c_str(), ui.answerList);
	}
}

void QuestionsAndAnswersObserver::handleSearchButton()
{
	ui.searchList->clear();

	std::string data = ui.searchLineEdit->text().toStdString();

	std::vector<Question> result = controller.searchQuestion(data);

	for (auto i : result)
	{
		std::string print = std::to_string(i.getId()) + "," + i.getText() + "," + i.getName();
		new QListWidgetItem(print.c_str(), ui.searchList);
	}
	ui.searchLineEdit->clear();
}

void QuestionsAndAnswersObserver::handleAddButton()
{
	std::string data = ui.addLineEdit->text().toStdString();
	if (data == "")
	{
		QMessageBox q;
		q.critical(0, "Problem", "Put something there");
	}
	else
	{
		this->controller.addQuestion(rand()%100, data, user.getName(), 0);
		this->populateList();
	}
	ui.addLineEdit->clear();
}

void QuestionsAndAnswersObserver::handleSelect(QListWidgetItem* h)
{
	int poz = ui.questionsList->currentIndex().row();
	std::vector<Question> list = controller.getQuestions();
	sort(list.begin(), list.end(), cmp);
	int qid = list[poz].getId();
	std::vector<Answer> result = controller.getAnswer(qid);
	this->populateAnswers(qid);

}

void QuestionsAndAnswersObserver::handleAddAnswer()
{
	int poz = ui.questionsList->currentIndex().row();
	std::vector<Question> questions = controller.getQuestions();
	sort(questions.begin(), questions.end(), cmp);
	Question selected = questions[poz];

	std::string data = ui.addAnsLineEdit->text().toStdString();
	if (data == "")
	{
		QMessageBox q;
		q.critical(0, "Problem", "Put something there");
	}
	else
	{
		controller.addAnswer(rand() % 100, selected.getId(), user.getName(), data, 0);
		this->populateAnswers(selected.getId());
	}
	ui.addAnsLineEdit->clear();
}