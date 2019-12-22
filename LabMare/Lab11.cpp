#include "Lab11.h"

Lab11::Lab11(Controller &controller, QWidget *parent)
	:QMainWindow(parent), controller(controller)
{
	ui.setupUi(this);

	this->model = new EvidenceModel{ *this->controller.getUserList() };
	this->model->reset();

	this->populate();
	this->populateUser();

	connect(ui.addButton, SIGNAL(released()), this, SLOT(handleAddButton()));
	connect(ui.deleteButton, SIGNAL(released()), this, SLOT(handleDeleteButton()));
	connect(ui.updateButton, SIGNAL(released()), this, SLOT(handleUpdateButton()));
	connect(ui.saveButton, SIGNAL(released()), this, SLOT(handleSaveButton()));
	connect(ui.nextButton, SIGNAL(released()), this, SLOT(handleNextButton()));
	connect(ui.filterButton, SIGNAL(released()), this, SLOT(handleFilterButton()));
	connect(ui.undoButton, SIGNAL(released()), this, SLOT(handleUndoButton()));
	connect(ui.redoButton, SIGNAL(released()), this, SLOT(handleRedoButton()));

	connect(ui.mylistButton, SIGNAL(released()), this, SLOT(handelMyListButton()));

	QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
	QShortcut *shortcut2 = new QShortcut(QKeySequence("Ctrl+Y"), this);
	connect(shortcut, SIGNAL(activated()), this, SLOT(handleUndoButton()));
	connect(shortcut2, SIGNAL(activated()), this, SLOT(handleRedoButton()));
}

void Lab11::populate()
{
	ui.evidenceData->clear();
	for (Evidence &evidence : this->controller.getAllEvidence())
	{
		ui.evidenceData->addItem(QString::fromStdString(evidence.displayEvidence()));

	}
}

void Lab11::populateUser()
{
	ui.userDataBase->clear();
	for (Evidence &evidence : this->controller.getMyListOfEvidence())
	{
		ui.userDataBase->addItem(QString::fromStdString(evidence.displayEvidence()));
	}
}

void Lab11::handleAddButton()
{
	std::string id = ui.IDEdit->text().toStdString();
	std::string measurement = ui.measurementEdit->text().toStdString();
	std::string imageClarityLevel = ui.imageClarityEdit->text().toStdString();
	std::string quantity = ui.quantityedit->text().toStdString();
	std::string photo = ui.photographEdit->text().toStdString();

	if (id.length() == 0 || measurement.length() == 0 || imageClarityLevel.length() == 0
		|| quantity.length() == 0 || photo.length() == 0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Something went wrong");
		return;
	}

	this->controller.addEvidenceToRepository(id, measurement, stof(imageClarityLevel),
		stof(quantity), photo);

	this->populate();

	ui.IDEdit->clear();
	ui.measurementEdit->clear();
	ui.imageClarityEdit->clear();
	ui.quantityedit->clear();
	ui.photographEdit->clear();
}

void Lab11::handleDeleteButton()
{
	std::string id = ui.IDEdit->text().toStdString();
	if (id.length() == 0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Something went wrong");
		return;
	}

	this->controller.deleteEvidenceFromRepository(id);

	this->populate();

	ui.IDEdit->clear();

}

void Lab11::handleUpdateButton()
{
	std::string id = ui.IDEdit->text().toStdString();
	std::string measurement = ui.measurementEdit->text().toStdString();
	std::string imageClarityLevel = ui.imageClarityEdit->text().toStdString();
	std::string quantity = ui.quantityedit->text().toStdString();
	std::string photo = ui.photographEdit->text().toStdString();

	if (id.length() == 0 || measurement.length() == 0 || imageClarityLevel.length() == 0
		|| quantity.length() == 0 || photo.length() == 0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Something went wrong");
		return;
	}

	this->controller.updateEvidence(id, measurement, stof(imageClarityLevel),
		stof(quantity), photo);

	this->populate();


	ui.IDEdit->clear();
	ui.measurementEdit->clear();
	ui.imageClarityEdit->clear();
	ui.quantityedit->clear();
	ui.photographEdit->clear();
}

void Lab11::handleSaveButton()
{
	std::string id = ui.IDuserEdit->text().toStdString();
	if (id.length() == 0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Something went wrong");
		return;
	}


	this->controller.addEvidenceToMyList(id);
	this->populateUser();
	this->model->rowInserted();

	ui.IDuserEdit->clear();
}

void Lab11::handleNextButton()
{
	ui.IDuserEdit->clear();
	ui.currentEvidence->clear();
	int current = this->controller.getUserIndex();
	std::string id = this->controller.getAllEvidence()[current].getId();
	Evidence evidence = this->controller.getAllEvidence()[current];
	ui.currentEvidence->addItem(QString::fromStdString(evidence.displayEvidence()));
	ui.IDuserEdit->setText(QString::fromStdString(id));
	this->controller.setUserIndex();
	
}

void Lab11::handleFilterButton()
{
	ui.filterList->clear();
	std::string measurement = ui.filterMeasurementEdit->text().toStdString();
	float quantity = ui.filterQuantityEdit->text().toFloat();
	std::vector<Evidence> result = this->controller.filter(measurement, quantity);
	for (Evidence &evidence : result)
	{
		ui.filterList->addItem(QString::fromStdString(evidence.displayEvidence()));
	}

	ui.filterMeasurementEdit->clear();
	ui.filterQuantityEdit->clear();

}

void Lab11::handleUndoButton()
{
	//ui.filterList->clear();
	//if (this->controller.undoLastAction())
	//{
		ui.evidenceData->clear();
		this->controller.undoLastAction();
		this->populate();
	//}
	//else
	/*{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Nothing to undo");
		return;
	}*/

}

void Lab11::handleRedoButton()
{
	//if (this->controller.redo())
	//{
		ui.evidenceData->clear();
		this->controller.redo();
		this->populate();
	//}
	/*else
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Nothing to redo");
		return;
	}*/
}

void Lab11::handelMyListButton()
{
	model->reset();
	model = new EvidenceModel{ *this->controller.getUserList() };
	view = new userView{ &*model };
	view->show();

	//this->controller.openFile();

}


