#pragma once

#include "Repo.h"
#include "Subject.h"

class Controller:public Subject
{
private:
	Repo * repo;

public:
	Controller(Repo * repo) :repo(repo) {}
	~Controller() {}

	std::vector<Programmer> getProgrammers()
	{
		return repo->getProgrammers();
	}
	std::vector<Task> getTasks()
	{
		return repo->getTasks();
	}
	void removeTask(int poz)
	{
		this->repo->removeTask(poz);
		this->notfiy();
	}
	void addTask(std::string d, int s, int i)
	{
		this->repo->addTask(d, s, i);
		this->notfiy();
	}

	void setTask(int poz, int status, int id)
	{
		this->repo->setTask(poz, status, id);
		this->notfiy();
	}


};