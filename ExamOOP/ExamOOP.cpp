#include "ExamOOP.h"
#include "qmessagebox.h"
#include "qcolor.h"
#include "qbrush.h"

ExamOOP::ExamOOP(Controller & controller, Ethnologist ethnologist,QWidget *parent)
	: QMainWindow(parent),controller(controller), ethnologist(ethnologist)
{
	ui.setupUi(this);

	this->populate();

	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));
	connect(ui.updateButton, SIGNAL(clicked()), this, SLOT(handleUpdateButton()));
}

bool cmp(Building a, Building b)
{
	return a.getThematicSector() < b.getThematicSector();
}

void ExamOOP::populate()
{
	ui.listWidget->clear();
	std::vector<Building> list = controller.getBuildings();
	//sort(list.begin(), list.end(), cmp);


	std::vector<Building> sorted = controller.sort(list,ethnologist.getThematicSector());

	for (auto i : list)
	{
		std::string print = std::to_string(i.getId()) + "," + i.getDescription() + "," + std::to_string(i.getYear()) + "," + i.getThematicSector() + "," +
			std::to_string(i.getLocation().getX()) +","+ std::to_string(i.getLocation().getY());

		if (i.getThematicSector() == ethnologist.getThematicSector())
		{
			QListWidgetItem * i= new QListWidgetItem(print.c_str(), ui.listWidget);
			i->setBackground(Qt::green);
		}
		else
		{
			QListWidgetItem * i = new QListWidgetItem(print.c_str(), ui.listWidget);
			i->setBackground(Qt::yellow);
		}

	}


}



void ExamOOP::handleAddButton()
{
	int id = ui.idLineEdit->text().toInt();
	std::string descr = ui.descrLineEdit->text().toStdString();
	int year = ui.yearLineEdit->text().toInt();
	int x = ui.xLineEdit->text().toInt();
	int y = ui.yLineEdit->text().toInt();

	std::vector<Building> list = controller.getBuildings();

	int ok = 0;;
	for (auto i : list)
	{
		if (i.getId() == id)
		{
			ok = 1;
		}
	}
	
	if (descr == "" || year > 1970 || year < 0)
	{
		QMessageBox q;
		q.critical(0, "problem", "try again");
	}
	else if (ok == 1)
	{
		QMessageBox q;
		q.critical(0, "problem", "already there");
	}
	else if (controller.getAverageDistance(ethnologist.getThematicSector(),x,y)>100)
	{
		QMessageBox q;
		q.critical(0, "problem", "too far away");
	}
	else
	{
		this->controller.addBuilding(id, descr, year, ethnologist.getThematicSector(), x, y);
		this->populate();
	}

	ui.idLineEdit->clear();
	ui.descrLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.xLineEdit->clear();
	ui.yLineEdit->clear();



}

void ExamOOP::handleUpdateButton()
{
	int poz = ui.listWidget->currentIndex().row();

	int id = ui.idLineEdit->text().toInt();
	std::string descr = ui.descrLineEdit->text().toStdString();
	int year = ui.yearLineEdit->text().toInt();
	int x = ui.xLineEdit->text().toInt();
	int y = ui.yLineEdit->text().toInt();

	std::vector<Building> list = controller.getBuildings();

	//std::vector<Building> list = controller.getBuildings();
	//sort(list.begin(), list.end(), cmp);


	//std::vector<Building> sorted = controller.sort(list, ethnologist.getThematicSector());

	Building current = controller.getBuildingByIndex(poz);

	int ok = 0;;
	for (auto i : list)
	{
		if (i.getId() == id)
		{
			ok = 1;
		}
	}

	if (descr == "" || year > 1970 || year < 0)
	{
		QMessageBox q;
		q.critical(0, "problem", "try again");
	}
	else if (ok == 1)
	{
		QMessageBox q;
		q.critical(0, "problem", "already there");
	}
	/*else if (controller.getAverageDistance(ethnologist.getThematicSector(), x, y) > 100)
	{
		QMessageBox q;
		q.critical(0, "problem", "too far away");
	}*/
	else if (current.getThematicSector() == ethnologist.getThematicSector())
	{
		this->controller.update(poz, id, descr, year, x, y);
		this->populate();
	}
	else if (current.getThematicSector() != ethnologist.getThematicSector())
	{
		QMessageBox q; 
		q.critical(0, "Problem", "n-ai dreptul");
	}

	/*if (current.getThematicSector() == ethnologist.getThematicSector())
	{
		this->controller.update(poz, id, descr, year, x, y);
		this->populate();
	}
	else if (current.getThematicSector() != ethnologist.getThematicSector() || controller.getAverageDistance(ethnologist.getThematicSector(), x, y) > 100 ||
		ok == 1 || descr == "" || year > 1970 || year < 0)
	{
		QMessageBox q;
		q.critical(0, "problem", "try again");
	}*/

	ui.idLineEdit->clear();
	ui.descrLineEdit->clear();
	ui.yearLineEdit->clear();
	ui.xLineEdit->clear();
	ui.yLineEdit->clear();
}