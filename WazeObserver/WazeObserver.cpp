#include "WazeObserver.h"
#include "qmessagebox.h"

WazeObserver::WazeObserver(Controller&controller,Driver driver,QWidget *parent)
	: QMainWindow(parent),controller(controller),driver(driver)
{
	ui.setupUi(this);

	this->populate();


	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));
	connect(ui.validateButton, SIGNAL(clicked()), this, SLOT(handleValidate()));
}

bool cmp(Report a, Report b)
{
	return a.getLocation().getLatitude()*a.getLocation().getLongitude() <
		b.getLocation().getLatitude()*b.getLocation().getLongitude();
}

void WazeObserver::populate()
{
	std::vector<Report> list = controller.getReports();
	sort(list.begin(), list.end(), cmp);

	ui.reportList->clear();

	for (auto i : list)
	{
		if (i.getLocation().getLatitude()*i.getLocation().getLongitude() - driver.getLocation().getLatitude()*driver.getLocation().getLongitude() < 10)
		{
			std::string print = i.getDescription() + "," + i.getReporter() + "->" + std::to_string(i.getLocation().getLatitude()) + "," + std::to_string(i.getLocation().getLongitude())+"    "+i.getValid();
			new QListWidgetItem(print.c_str(), ui.reportList);  
		}
	}
}

void WazeObserver::handleAddButton()
{
	std::string descr = ui.descrLineEdit->text().toStdString();
	int lat = ui.latLineEdit->text().toInt();
	int lon = ui.lonLineEdit->text().toInt();

	if (descr == "")
	{
		QMessageBox q;
		q.critical(0, "problem", "put something there");
	}
	else if (lat*lon - driver.getLocation().getLatitude()*driver.getLocation().getLongitude() > 20)
	{
		QMessageBox q;
		q.critical(0, "problem", "too far away");
	}
	else
	{
		this->controller.addReport(descr, driver.getName(), lat, lon, 1);
		this->populate();
	}
	ui.descrLineEdit->clear();
	ui.latLineEdit->clear();
	ui.lonLineEdit->clear();


}

void WazeObserver::handleValidate()
{
	int nr = ui.reportList->currentIndex().row();
	std::vector<Report> list = controller.getReports();
	sort(list.begin(), list.end(), cmp);
	Report current = list[nr];

	if (current.getValidInt() == 1)
	{
		current.setValid(2);
		this->populate();
	}
	else if (current.getValidInt() == 0)
	{
		current.setValid(1);
		this->populate();
	}
	else if (current.getValidInt() == 2)
	{
		QMessageBox q;
		q.critical(0, "Problem", "Already validated");
	}
	//this->populate();

}