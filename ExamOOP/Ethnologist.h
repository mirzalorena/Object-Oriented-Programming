#pragma once

#include <string>

class Ethnologist
{
private:
	std::string name;
	std::string thematicSector;

public:
	Ethnologist(std::string name, std::string thematicSector) :name(name), thematicSector(thematicSector) {}
	~Ethnologist() {}

	std::string getName() { return this->name; }
	std::string getThematicSector() { return this->thematicSector; }


};