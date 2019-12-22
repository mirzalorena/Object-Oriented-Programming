#pragma once

#include "Driver.h"
#include <string>

class Report
{
private:
	std::string description;
	std::string reporter;
	Location location;
	int valid;

public:
	Report(std::string description, std::string
		reporter, Location location, int valid) :
		description(description), reporter(reporter),
		location(location), valid(valid) {}
	~Report() {}

	std::string getDescription() { return this->description; }
	std::string getReporter() { return this->reporter; }
	Location getLocation() { return this->location; }
	std::string getValid()
	{
		std::vector<std::string> option = { "false","false","true" };
		return option[valid];
	}
	int getValidInt()
	{
		return this->valid;
	}

	void setValid(int valid) { this->valid = valid; }
	

};