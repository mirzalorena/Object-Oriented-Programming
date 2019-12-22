#include "FileRepository.h"
#include "Exception.h"
#include <fstream>
#include <iostream>
#include <assert.h>
#include <iostream>
#include "qt_windows.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;

FileRepository::FileRepository()
{

}

FileRepository::FileRepository(std::string fileName)
{
	this->filePath = fileName;
	this->readFromFile();
}

std::string FileRepository::getPath()
{
	return this->filePath;
}

void FileRepository::settings(std::string newPath)
{
	this->filePath = newPath;
}

void FileRepository::openFile()
{
	system(this->filePath.c_str());
}

void FileRepository::loadData()
{
	std::vector<Evidence> allEvidence = this->readFromFile();
	for (int i = 0; i < allEvidence.size(); i++)
	{
		allEvidence.push_back(allEvidence[i]);
	}
}

void FileRepository::addEvidence(Evidence evidence)
{
	Evidence toSearch{};
	std::vector<Evidence> allEvidence = this->readFromFile();
	allEvidence.push_back(evidence);
	this->writeToFile(allEvidence);
}

void FileRepository::deleteEvidence(std::string id)
{
	std::vector<Evidence> allElements = this->readFromFile();
	int positionToDelete = this->findPositionById(id);
	//if (positionToDelete < 0 || positionToDelete >= allElements.size())
	//	throw(Exception("This element does not exist\n"));
	allElements.erase(allElements.begin() + positionToDelete);
	this->writeToFile(allElements);

}

void FileRepository::updateEvidence(std::string id, Evidence newEvidence)
{
	std::vector<Evidence> allElements = this->readFromFile();
	int positionToUpdate = this->findPositionById(id);
	//if (positionToUpdate < 0 || positionToUpdate >= allElements.size())
	//	throw(Exception("This element does not exist\n"));
	//allElements[positionToUpdate] = newEvidence;
	allElements[positionToUpdate].setMeasurement(newEvidence.getMeasurement());
	allElements[positionToUpdate].setImageClarityLevel(newEvidence.getimageClarityLevel());
	allElements[positionToUpdate].setQuantity(newEvidence.getQuantity());
	allElements[positionToUpdate].setPhotograph(newEvidence.getPhotograph());
	this->writeToFile(allElements);
}

int FileRepository::findPositionById(std::string id)
{
	std::vector<Evidence> allEvidence = this->readFromFile();
	for (size_t i = 0; i < allEvidence.size(); i++)
		if (allEvidence[i].getId() == id)
			return i;
	return -1;
}

Evidence FileRepository::findById(std::string id)
{
	std::vector<Evidence> allEvidence = this->readFromFile();
	for (auto evidence : allEvidence)
		if (evidence.getId() == id)
			return evidence;
}


std::vector<Evidence> FileRepository::getEvidence()
{
	return this->readFromFile();
}

std::vector<Evidence> FileRepository::readFromFile()
{
	std::vector<Evidence> allEvidence;
	ifstream file(this->filePath);
	//if (!file.is_open())
	//	throw FileException("Something went wrong");
	Evidence evidence;
	while (file >> evidence)
	{
		//this->evidenceDataBase.push_back(evidence);
		allEvidence.push_back(evidence);
	}
	return allEvidence;
	file.close();

}



void FileRepository::writeToFile(std::vector<Evidence> allEvidence)
{
	std::ofstream writeFile(this->filePath);
	//if (!writeFile.is_open())
	//{
	//	throw FileException("Something went wrong");
	//}
	for (auto evidence : allEvidence)
		writeFile << evidence;

	writeFile.close();
}



FileRepository::~FileRepository()
{

}



