#pragma once

#include <string>

class Astronomer
{
private:
	std::string name;
	std::string constellation;

public:
	Astronomer(std::string name, std::string constellation) :
		name(name), constellation(constellation) {}
	~Astronomer() {}

	std::string getName() { return this->name; }
	std::string getConstellation() { return this->constellation; }



};