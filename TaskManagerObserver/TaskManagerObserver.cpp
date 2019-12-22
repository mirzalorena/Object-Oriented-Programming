#include "TaskManagerObserver.h"
#include "qmessagebox.h"

TaskManagerObserver::TaskManagerObserver(Controller & controller, Programmer programmer, QWidget *parent)
	: QMainWindow(parent),controller(controller),programmer(programmer)
{
	ui.setupUi(this);
	
	this->populateList();

	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));
	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(handleStart()));
	connect(ui.doneButton, SIGNAL(clicked()), this, SLOT(handleDone()));
	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(handleRemove()));
}

bool cmp(Task a, Task b)
{
	return a.getStatus() > b.getStatus();
}

void TaskManagerObserver::populateList()
{
	ui.tasksList->clear();
	std::vector<Task> list = controller.getTasks();
	sort(list.begin(), list.end(), cmp);
	for (auto i : list)
	{
		std::string print = i.getDescription() + "," + i.getStatus() + "," + std::to_string(i.getId());
		new QListWidgetItem(print.c_str(), ui.tasksList);
	}
}

void TaskManagerObserver::handleAddButton()
{
	std::string data = ui.addLineEdit->text().toStdString();

	if (data != "")
	{
		this->controller.addTask(data, 0, programmer.getId());
	}
	this->populateList();


}

void TaskManagerObserver::handleStart()
{
	int nr = ui.tasksList->currentIndex().row();
	std::vector<Task> list = controller.getTasks();
	if (list[nr].getStatus() == "open")
	{
		this->controller.setTask(nr, 1, programmer.getId());
		this->populateList();
	}
	else
	{
		QMessageBox q;
		q.critical(0, "Altadata", "Data viitoare");
	}
}

void TaskManagerObserver::handleDone()
{
	int nr = ui.tasksList->currentIndex().row();
	std::vector<Task> list = controller.getTasks();
	if (list[nr].getStatus() == "in progress" && list[nr].getId() == programmer.getId())
	{
		this->controller.setTask(nr, 2, list[nr].getId());
		this->populateList();
	}
	else
	{
		QMessageBox q;
		q.critical(0, "Altadata", "Data viitoare");
	}
}

void TaskManagerObserver::handleRemove()
{
	int poz = ui.tasksList->currentIndex().row();
	this->controller.removeTask(poz);
	this->populateList();
}