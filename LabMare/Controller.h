#pragma once
#include "Repository.h"
#include "EvidenceValidator.h"
#include "Undo.h"
#include <vector>
#include <algorithm>
#include <memory>
#include "Observer.h"

class Controller:public Subject
{
private:
	Repository *repository;
	Repository *userRepository;
	EvidenceValidator validator;
	int currentIndex;

	std::vector<std::shared_ptr<UndoAction>> historyOfCommands;
	//std::vector<std::shared_ptr<UndoAction>> redoHistory;
	int currentUndoRedoAction;


public:
	Controller(Repository *repository,
		Repository *userRepository,
		EvidenceValidator validator);

	void loadData();

	void addEvidenceToRepository(const std::string &id, const std::string &measurement,
		const float &imageClarityLevel, const float &quantity,
		const std::string &photograph);
	void addEvidenceToMyList(std::string);
	void deleteEvidenceFromRepository(std::string id);
	void updateEvidence(const std::string &id, const std::string &measurement,
		const float &imageClarityLevel, const float &quantity,
		const std::string &photograph);
	std::vector<Evidence> getAllEvidence();
	std::vector<Evidence> getMyListOfEvidence();
	Repository* getUserList() { return this->userRepository; }

	std::string getFileNameUser();

	void setFileName(std::string newName);
	void setFileNameUser(std::string newName);

	int getUserIndex();
	void setUserIndex();

	void openFile();

	std::vector<Evidence> filter(std::string measurement, float quantity);

	bool undoLastAction();
	bool redo();

	void deleteRedo();

	~Controller() {}

};