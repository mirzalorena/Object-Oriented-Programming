#include "MemoryRepository.h"
#include "Repository.h"
#include "Exception.h"
#include <assert.h>

MemoryRepository::MemoryRepository()
{

}

std::vector<Evidence> MemoryRepository::getEvidence()
{
	return this->evidenceDataBase;
}

void MemoryRepository::settings(std::string newPath) {}

int MemoryRepository::findPositionById(std::string id)
{
	for (size_t i = 0; i < evidenceDataBase.size(); i++)
		if (evidenceDataBase[i].getId() == id)
			return i;
	return -1;

}

Evidence MemoryRepository::findById(std::string id)
{
	for (auto evidence : this->evidenceDataBase)
		if (evidence.getId() == id)
			return evidence;
}


void MemoryRepository::deleteEvidence(std::string id)
{
	int positionToDelete = this->findPositionById(id);
	if (positionToDelete < 0 || positionToDelete >= this->evidenceDataBase.size())
		throw(Exception("This element does not exist\n"));
	this->evidenceDataBase.erase(this->evidenceDataBase.begin() + positionToDelete);
}

void MemoryRepository::updateEvidence(std::string id, Evidence newEvidence)
{
	int positionToUpdate = this->findPositionById(id);
	if (positionToUpdate < 0 || positionToUpdate >= this->evidenceDataBase.size())
		throw(Exception("This element does not exist\n"));
	this->evidenceDataBase[positionToUpdate] = newEvidence;
}

void MemoryRepository::addEvidence(Evidence evidence)
{
	Evidence toSearch{};
	this->evidenceDataBase.push_back(evidence);

}

void MemoryRepository::tests()
{
	this->addTest();
	this->deleteTest();
	this->updateTest();
}

void MemoryRepository::updateTest()
{
	MemoryRepository repository;
	Evidence evidence1{ "12e","5x5x5",6,7,"DSC67.jpg" };
	repository.addEvidence(evidence1);
	Evidence newEvidence{ "12e","9x9x9",3,4,"DSC45.jpg" };
	repository.updateEvidence("12e", newEvidence);

	assert(repository.evidenceDataBase[0].getMeasurement() == "9x9x9");
	assert(repository.evidenceDataBase[0].getimageClarityLevel() == 3);
	assert(repository.evidenceDataBase[0].getQuantity() == 4);
	assert(repository.evidenceDataBase[0].getPhotograph() == "DSC45.jpg");

	try
	{
		Evidence evidence2{ "67","7x7x7x",3,4,"udhre" };
		repository.updateEvidence("67", evidence2);
	}
	catch (Exception &updateException)
	{
		assert(true);
	}


}

void MemoryRepository::deleteTest()
{
	MemoryRepository repository;
	Evidence evidence1{ "12e","5x5x5",6,7,"DSC67.jpg" };
	repository.addEvidence(evidence1);
	Evidence evidence2{ "145","9x9x9",3,4,"DSC45.jpg" };
	repository.addEvidence(evidence2);

	assert(repository.findPositionById("145") == 1);
	assert(repository.findPositionById("5") == -1);

	repository.deleteEvidence("12e");
	assert(repository.evidenceDataBase.size() == 1);

	try
	{
		repository.deleteEvidence("78u");
	}
	catch (Exception &deleteException)
	{
		assert(true);
	}

}

void MemoryRepository::addTest()
{
	MemoryRepository repository;
	Evidence evidence1{ "12e","5x5x5",6,7,"DSC67.jpg" };
	repository.addEvidence(evidence1);

	assert(repository.evidenceDataBase.size() == 1);

	Evidence evidence2{ "145","9x9x9",3,4,"DSC45.jpg" };
	repository.addEvidence(evidence2);

	assert(repository.evidenceDataBase.size() == 2);

	try
	{
		repository.addEvidence(evidence1);
	}
	catch (Exception &addException)
	{
		assert(addException.get_message() == "Already there\n");
	}

	Evidence evidence3{ "12e","5x5x5",6,7,"DSC67.jpg" };
	assert(evidence1 == evidence3);

	std::string evidence = evidence1.displayEvidence();
	//assert(evidence == "12e 5x5x5 6 7 DSC67.jpg");
	//std::string evidenceForFile = evidence1.displayEvidenceFile();
	//assert(evidenceForFile == "12e, 5x5x5, 6, 7, DSC67.jpg");

}