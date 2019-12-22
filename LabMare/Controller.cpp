#include "Controller.h"
#include "Exception.h"
#include "FileRepository.h"
#include "MemoryRepository.h"
#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

Controller::Controller(Repository *repository,
	Repository *userRepository,
	EvidenceValidator validator) :
	repository{ repository }, userRepository{ userRepository },
	validator{ validator }
{
	this->currentIndex = 0;
	this->currentUndoRedoAction = -1;
}

void Controller::loadData()
{
	FileRepository* fileRepository = dynamic_cast<FileRepository*>(this->repository);
	fileRepository->loadData();
}

std::vector<Evidence> Controller::filter(std::string measurement, float quantity)
{
	std::vector<Evidence> result;
	std::vector<Evidence> allEvidence = this->userRepository->getEvidence();
	for (Evidence &evidence : allEvidence)
	{
		if (evidence.getMeasurement() == measurement|| evidence.getQuantity() >= quantity)
			result.push_back(evidence);
	}
	return result;
}

bool Controller::undoLastAction()
{
	if (currentUndoRedoAction>=0)
	{
		/*int index = this->historyOfCommands.size() - 1;
		this->historyOfCommands[index]->executeUndo();
		shared_ptr<UndoAction> pointer = std::move(this->historyOfCommands[index]);
		this->historyOfCommands.pop_back();
		//this->historyOfCommands.back().get();
		this->redoHistory.push_back(std::move(pointer));*/

		/*<UndoAction> action = this->historyOfCommands.at(this->historyOfCommands.size() - 1);
		this->historyOfCommands.pop_back();
		action->executeUndo();
		this->redoHistory.push_back(std::move(action));*/

		/*int index = this->historyOfCommands.size() - numberUndo + numberRedo - 1;
		if (index < 0 || numberUndo >= this->historyOfCommands.size() || undoAction < 0)
			return false;
		else
		{
			this->historyOfCommands[index].get()->executeUndo();
			this->numberUndo++;
			this->undoAction++;
		}*/

		this->historyOfCommands[currentUndoRedoAction]->executeUndo();
		this->currentUndoRedoAction -= 1;

		return true;
	}
	return false;
}

bool Controller::redo()
{
	if (this->currentUndoRedoAction!=this->historyOfCommands.size()-1)
	{
		/*int index = this->redoHistory.size() - 1;
		this->redoHistory[index]->executeRedo();
		shared_ptr<UndoAction> pointer = std::move(this->redoHistory[index]);
		this->redoHistory.pop_back();
		this->historyOfCommands.push_back(std::move(pointer));*/

		/*shared_ptr<UndoAction> action = this->redoHistory.at(this->redoHistory.size() - 1);
		this->redoHistory.pop_back();
		action->executeRedo();
		this->historyOfCommands.push_back(std::move(action));*/

		this->currentUndoRedoAction += 1;
		this->historyOfCommands[currentUndoRedoAction]->executeRedo();

		return true;
	}
	return false;
}

void Controller::deleteRedo()
{
	if (this->historyOfCommands.size() > 0 && currentUndoRedoAction < historyOfCommands.size())
	{
		this->historyOfCommands.erase(this->historyOfCommands.begin() + currentUndoRedoAction + 1, this->historyOfCommands.end());
	}
}

void Controller::addEvidenceToMyList(std::string id)
{
	Evidence evidence = this->repository->findById(id);
	this->userRepository->addEvidence(evidence);

}

void Controller::addEvidenceToRepository(const std::string &id, const std::string &measurement,
	const float &imageClarityLevel, const float &quantity,
	const std::string &photograph)
{
	Evidence evidence{ id,measurement,imageClarityLevel,quantity,photograph };
	
		this->validator.validate(evidence);

		this->repository->addEvidence(evidence);
	
		this->deleteRedo();

		UndoAdd undoAddOperation = UndoAdd(evidence, *repository);
		//undoAddOperation.setAddedEvidence(evidence);
		shared_ptr<UndoAction> pointer = std::make_shared<UndoAdd>(undoAddOperation);
		this->historyOfCommands.push_back(std::move(pointer));
		this->currentUndoRedoAction += 1;

}

void Controller::deleteEvidenceFromRepository(std::string id)
{
		Evidence evidence = this->repository->findById(id);
	
		this->repository->deleteEvidence(id);

		this->deleteRedo();

		UndoRemove undoRemoveOperation = UndoRemove(evidence, *repository);
		//undoRemoveOperation.setDeletedEvidence(evidence);
		shared_ptr<UndoAction> pointer = std::make_shared<UndoRemove>(undoRemoveOperation);
		historyOfCommands.push_back(std::move(pointer));
		this->currentUndoRedoAction += 1;
}

void Controller::updateEvidence(const std::string &id, const std::string &measurement,
	const float &imageClarityLevel, const float &quantity,
	const std::string &photograph)
{
	Evidence newEvidence{ id,measurement,imageClarityLevel,quantity,photograph };

	Evidence old = this->repository->findById(id);

	this->validator.validate(newEvidence);
	
	this->repository->updateEvidence(id, newEvidence);

	this->deleteRedo();

	UndoUpdate undoUpdateOperation = UndoUpdate(old, newEvidence, *repository);
	//undoUpdateOperation.setUpdatedEvidence(old);
	shared_ptr<UndoUpdate> pointer = std::make_shared<UndoUpdate>(undoUpdateOperation);
	historyOfCommands.push_back(std::move(pointer));
	this->currentUndoRedoAction += 1;
}

std::vector<Evidence> Controller::getAllEvidence()
{
	return this->repository->getEvidence();
}
std::vector<Evidence> Controller::getMyListOfEvidence()
{
	return this->userRepository->getEvidence();
}

std::string Controller::getFileNameUser()
{
	FileRepository* userFileRepository = dynamic_cast<FileRepository*>(this->userRepository);
	//if (userFileRepository == NULL)
	//	throw(Exception("Something went wrong\n"));
	return userFileRepository->getPath();
}

void Controller::setFileName(std::string newName)
{
	this->repository->settings(newName);
}

void Controller::setFileNameUser(std::string newName)
{
	this->userRepository->settings(newName);
}

int Controller::getUserIndex()
{
	return this->currentIndex;
}

void Controller::setUserIndex()
{
	this->currentIndex++;
	if (this->currentIndex == this->getAllEvidence().size())
		this->currentIndex = 0;
}

void Controller::openFile()
{
	FileRepository* fileRepository = dynamic_cast<FileRepository*>(this->userRepository);
	fileRepository->openFile();
}

