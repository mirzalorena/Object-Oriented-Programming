#pragma once

#include <string>

class User
{
private:
	std::string name;

public:
	User(std::string name) :name(name) {}
	~User() {}

	std::string getName() { return this->name; }


};