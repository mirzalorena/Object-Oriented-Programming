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
		"in progress","close" };
		return option[status];
	}
	int getId() { return this->id; }

	void setDescription(std::string d) { this->description = d; }
	void setStatus(int s) { this->status = s; }
	void setId(int id) { this->id = id; }



};