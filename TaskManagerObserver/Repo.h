#pragma once

#include <vector>
#include "Programmer.h"
#include "Task.h"

class Repo
{
private:
	std::vector<Programmer> programmers;
	std::vector<Task> tasks;

public:
	Repo();
	~Repo() {}

	void readData();

	std::vector<Programmer> getProgrammers() { return this->programmers; }
	std::vector<Task> getTasks() { return this->tasks; }

	void addProgrammer(std::string name, int id)
	{
		this->programmers.push_back(Programmer(name, id));
	}
	void addTask(std::string d, int s, int i)
	{
		this->tasks.push_back(Task(d, s, i));
	}
	void removeTask(int poz)
	{
		tasks.erase(tasks.begin() + poz);
	}
	void setTask(int poz, int status, int id)
	{
		this->tasks[poz].setStatus(status);
		this->tasks[poz].setId(id);
	}

};