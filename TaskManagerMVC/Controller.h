#pragma once

#include "Repo.h"

class Controller
{
private:
	Repo * repo;

public:
	Controller(Repo *) :repo(repo) {}
	~Controller() {}

	void addTask(std::string d, int s, int i)
	{
		repo->addTask(d, s, i);
	}
	void removeTask(int poz)

	{
		repo->removeTask(poz);
	}
	void set(int poz, int s, int i)
	{
		repo->setTask(poz, s, i);
	}
};