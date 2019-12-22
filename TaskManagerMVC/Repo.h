#pragma once

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

	std::vector<Programmer> getProgrammers()
	{
		return this->programmers;
	}
	std::vector<Task> getTasks()
	{
		return this->tasks;
	}
	int getNrofTasks()
	{
		return this->tasks.size();
	}

	Task getTaskByIndex(int index)
	{
		return tasks[index];
	}
	std::string getProgrNameById(int id)
	{
		for (auto p : programmers)
		{
			if (p.getId() == id)
				return p.getName();
		}
		return "";
	}

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
		this->tasks.erase(tasks.begin() + poz);
	}
	void setTask(int poz, int s, int id)
	{
		this->tasks[poz].setStatus(s);
		this->tasks[poz].setId(id);
	}


};