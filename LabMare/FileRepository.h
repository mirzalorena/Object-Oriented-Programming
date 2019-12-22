#pragma once
#include "Repository.h"
#include <string>
#include <vector>

class FileRepository :public Repository
{
private:
	std::string filePath;
	//std::vector<Evidence> evidenceDataBase;

public:
	FileRepository();

	FileRepository(std::string fileName);

	std::string getPath();
	void settings(std::string newPath) override;
	void openFile();

	void loadData();


	void addEvidence(Evidence evidence) override;
	void deleteEvidence(std::string id) override;
	void updateEvidence(std::string id, Evidence newEvidence) override;

	int findPositionById(std::string id) override;
	Evidence findById(std::string id) override;

	std::vector<Evidence> getEvidence() override;
	std::vector<Evidence> getEvidenceFromMemory();
	std::vector<Evidence> readFromFile();


	void writeToFile(std::vector<Evidence> allEvidence);
	
	~FileRepository();

};
