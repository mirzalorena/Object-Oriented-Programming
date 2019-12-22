#pragma once
#include "Repository.h"
#include "Exception.h"

class MemoryRepository :public Repository
{
private:
	std::vector<Evidence> evidenceDataBase;

public:
	MemoryRepository();
	void settings(std::string newPath) override;

	void addEvidence(Evidence evidence) override;
	void deleteEvidence(std::string id) override;
	void updateEvidence(std::string id, Evidence newEvidence) override;

	int findPositionById(std::string id) override;
	Evidence findById(std::string id) override;

	std::vector<Evidence> getEvidence() override;

	void tests();
	void addTest();
	void deleteTest();
	void updateTest();


};