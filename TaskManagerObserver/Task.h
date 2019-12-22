#pragma once

#include <string>
#include <vector>

class Task
{
private:
	std::string description;
	int status;
	int id;

public:
	Task(std::string description, int status, int id) :
		description(description), status(status),
		id(id) {}
	~Task() {}

	std::string getDescription() { return this->description; }
	std::string getStatus()
	{
		std::vector<std::string> option = { "open",
		"in progress","closed" };
		return option[status];
	}
	int getId() { return this->id; }

	void setDescription(std::string descr)
	{
		this->description = descr;
	}
	void setStatus(int status)
	{
		this->status = status;
	}
	void setId(int id)
	{
		this->id = id;
	}



};