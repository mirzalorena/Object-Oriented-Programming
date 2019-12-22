#pragma once

#include <string>

class Programmer
{
private:
	std::string name;
	int id;

public:
	Programmer(std::string name, int id) :
		name(name), id(id) {}
	~Programmer() {}

	std::string getName() { return this->name; }
	int getId() { return this->id; }

};