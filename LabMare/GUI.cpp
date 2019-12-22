#include "GUI.h"
#include <string>

//GUI::GUI() {}

GUI::GUI(Controller controller) :controller{ controller }
{
	this->init();
	this->populate();
}

GUI::~GUI() {}

void GUI::init()
{
	QHBoxLayout *layout = new QHBoxLayout{ this };

	//init boxes
	QVBoxLayout *layoutAdministrator = new QVBoxLayout{};
	QVBoxLayout *layoutConnect = new QVBoxLayout{};
	QVBoxLayout *layoutUser = new QVBoxLayout{};

	//setup administrator
	QLabel *adminLabel = new QLabel();
	adminLabel->setText("Evidence Data Base");
	QFont adminFont("Times New Roman", 14, QFont::Bold);
	adminLabel->setFont(adminFont);
	layoutAdministrator->addWidget(adminLabel);

	//setup user
	QLabel *userLabel = new QLabel();
	userLabel->setText("User Data Base");
	QFont userFont("Times New Roman", 14,QFont::Bold);
	userLabel->setFont(userFont);
	layoutUser->addWidget(userLabel);

	this->evidenceDataBase = new QListWidget{};
	this->userDataBase = new QListWidget{};

	layoutAdministrator->addWidget(this->evidenceDataBase);
	layoutUser->addWidget(this->userDataBase);

	QVBoxLayout *leftSide = new QVBoxLayout{};
	QVBoxLayout *rightSide = new QVBoxLayout{};

	layoutAdministrator->addLayout(leftSide);
	layoutUser->addLayout(rightSide);

	QHBoxLayout *buttons = new QHBoxLayout{};

	this->addButton = new QPushButton{ "Add" };
	buttons->addWidget(this->addButton);
	this->removeButton = new QPushButton{ "Delete" };
	buttons->addWidget(this->removeButton);
	this->updateButton = new QPushButton{ "Update" };
	buttons->addWidget(this->updateButton);
	this->saveButton = new QPushButton{ ">>" };
	layoutConnect->addWidget(this->saveButton);

	QHBoxLayout *nextLayout = new QHBoxLayout{};

	this->nextButton = new QPushButton{ "Next" };
	this->nextButton->setMaximumWidth(180);
	nextLayout->addWidget(this->nextButton);

	QFormLayout *repositoryData = new QFormLayout{};
	QFormLayout *userData = new QFormLayout{};

	this->id = new QLineEdit{};
	repositoryData->addRow("ID", this->id);
	this->measurement = new QLineEdit{};
	repositoryData->addRow("Measurement", this->measurement);
	this->imageClarityLevel = new QLineEdit{};
	repositoryData->addRow("Image Clarity Level", this->imageClarityLevel);
	this->quantity = new QLineEdit{};
	repositoryData->addRow("Quantity", this->quantity);
	this->photograph = new QLineEdit{};
	repositoryData->addRow("Photograph", this->photograph);

	leftSide->addLayout(repositoryData);
	leftSide->addLayout(buttons);
	rightSide->addLayout(nextLayout);

	layout->addLayout(layoutAdministrator);
	layout->addLayout(layoutConnect);
	layout->addLayout(layoutUser);

	this->connectSignalsAndSlots();

}

void GUI::populate()
{
	this->evidenceDataBase->clear();
	for (Evidence &evidence : this->controller.getAllEvidence())
	{
		this->evidenceDataBase->addItem(QString::fromStdString(evidence.displayEvidence()));

	}
}

void GUI::populateUser()
{
	this->userDataBase->clear();
	for (Evidence &evidence : this->controller.getMyListOfEvidence())
	{
		this->userDataBase->addItem(QString::fromStdString(evidence.displayEvidence()));
	}
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addEvidence()));
	QObject::connect(this->removeButton, SIGNAL(clicked()), this, SLOT(deleteEvidence()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateButton()));
	QObject::connect(this->saveButton, SIGNAL(clicked()), this, SLOT(saveUser()));
	QObject::connect(this->nextButton, SIGNAL(clicked()), this, SLOT(next()));
}

void GUI::addEvidence()
{
	std::string id = this->id->text().toStdString();
	std::string measurement = this->measurement->text().toStdString();
	std::string imageClarityLevel = this->imageClarityLevel->text().toStdString();
	std::string quantity = this->quantity->text().toStdString();
	std::string photo = this->photograph->text().toStdString();

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

}

void GUI::deleteEvidence()
{
	std::string id = this->id->text().toStdString();
	if(id.length()==0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Something went wrong");
		return;
	}

	this->controller.deleteEvidenceFromRepository(id);

}

void GUI::updateEvidence()
{
	std::string id = this->id->text().toStdString();
	std::string measurement = this->measurement->text().toStdString();
	std::string imageClarityLevel = this->imageClarityLevel->text().toStdString();
	std::string quantity = this->quantity->text().toStdString();
	std::string photo = this->photograph->text().toStdString();

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
}

void GUI::saveUser()
{
	std::string id = this->id->text().toStdString();
	if (id.length() == 0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Something went wrong");
		return;
	}
	
	this->controller.addEvidenceToMyList(id);
	this->populateUser();

}

void GUI::next()
{
	int current = this->controller.getUserIndex();
	std::string id = this->controller.getAllEvidence()[current].getId();
	this->id->setText(QString::fromStdString(id));
	this->controller.setUserIndex();
}