#pragma once

#include <string>

class Question
{
private:
	int id;
	std::string text;
	std::string name;
	int ans;

public:
	Question(int id, std::string text, std::string name,int ans) :
		id(id), text(text), name(name),ans(ans) {}
	~Question() {}

	int getId() { return this->id; }
	std::string getText() { return this->text; }
	std::string getName() { return this->name; }
	int getAns() { return this->ans; }

	void setName(std::string n) { this->name = n; }
	void setAns(int a) { this->ans = a; }
};