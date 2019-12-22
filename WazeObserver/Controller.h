#pragma once

#include "Repo.h"
#include "Subject.h"

class Controller:public Subject
{
private:
	Repo * repo;

public:
	Controller(Repo*repo) :repo(repo) {}
	~Controller() { }

	std::vector<Driver> getDrivers() { return repo->getDrivers(); }
	std::vector<Report> getReports() { return repo->getReports(); }

	void addReport(std::string d, std::string r, int la, int lo, int v)
	{
		this->repo->addReport(d, r, la, lo, v);
		this->notify();
	}


};