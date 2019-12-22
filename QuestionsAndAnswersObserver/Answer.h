#pragma once

#include <string>

class Answer
{
private:
	int id;
	int idq;
	std::string name;
	std::string text;
	int votes;

public:
	Answer(int id, int idq, std::string name, std::string text, int votes) :
		id(id), idq(idq), name(name), text(text), votes(votes) {}
	~Answer() {}

	int getId() { return this->id; }
	int getIdQ() { return this->idq; }
	std::string getName() { return this->name; }
	std::string getText() { return this->text; }
	int getVotes() { return this->votes; }




};