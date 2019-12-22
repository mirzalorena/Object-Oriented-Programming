#include "StarCatalogueMVC.h"
#include "qmessagebox.h"

StarCatalogueMVC::StarCatalogueMVC(Controller & controller,
	StarModel * model,
	Astronomer astronomer, QWidget *parent)
	: QMainWindow(parent),controller(controller),
	model(model),astronomer(astronomer)
{
	ui.setupUi(this);
	ui.tableView->setModel(model);
	setWindowTitle(QString::fromStdString(astronomer.getName()));

	populate();

	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(handleSearchButton()));
}

void StarCatalogueMVC::populate()
{
		model->updateAll();
		ui.tableView->resizeColumnsToContents();
	

}

void StarCatalogueMVC::handleAddButton()
{
	std::string name = ui.nameLineEdit->text().toStdString();
	int ra = ui.raLineEdit->text().toInt();
	int dec = ui.decLineEdit->text().toInt();

	this->controller.addStar(name, astronomer.getConstellation(), ra, dec, rand() % 100);

	populate();

	ui.nameLineEdit->clear();
	ui.raLineEdit->clear();
	ui.decLineEdit->clear();
}

void StarCatalogueMVC::handleSearchButton()
{
	std::string name = ui.nameLineEdit->text().toStdString();
	int ra = ui.raLineEdit->text().toInt();
	int dec = ui.decLineEdit->text().toInt();

	ui.searchList->clear();

	std::vector<Star> result = controller.search(name, ra, dec);

	for (auto i : result)
	{
		std::string print = i.getName() + "," + i.getConst();
		new QListWidgetItem(print.c_str(), ui.searchList);
	}

	ui.nameLineEdit->clear();
	ui.raLineEdit->clear();
	ui.decLineEdit->clear();

}