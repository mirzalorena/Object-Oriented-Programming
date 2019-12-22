#include "TaskManagerMVC.h"

TaskManagerMVC::TaskManagerMVC(Controller & controller,
	TaskModel * model,
	Programmer programmer, QWidget *parent)
	: QMainWindow(parent),controller(controller),
	model(model),programmer(programmer)
{
	ui.setupUi(this);
	ui.tasksView->setModel(model);
	setWindowTitle(QString::fromStdString(programmer.getName()));

	populate();

	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));
	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(handleRemoveButton()));
	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(handleStart()));
	connect(ui.doneButton, SIGNAL(clicked()), this, SLOT(handleDone()));
}

void TaskManagerMVC::populate()
{
	model->updateAll();
	ui.tasksView->resizeColumnsToContents();
}

void TaskManagerMVC::handleAddButton()
{
	std::string data = ui.addLineEdit->text().toStdString();
	ui.addLineEdit->clear();
	//if (data != "")
	//{
		this->controller.addTask(data, 0, programmer.getId());
		this->populate();
	//}
}

void TaskManagerMVC::handleRemoveButton()
{
	int nr = ui.tasksView->currentIndex().row();
	this->controller.removeTask(nr);
	this->populate();
}

void TaskManagerMVC::handleStart()
{
	//

}

void TaskManagerMVC::handleDone()
{
	//
}