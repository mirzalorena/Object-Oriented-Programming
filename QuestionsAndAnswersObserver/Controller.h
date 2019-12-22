#pragma once

#include "Repo.h"
#include "Subject.h"

class Controller :public Subject
{
private:
	Repo * repo;

public:
	Controller(Repo * repo) :repo(repo) {}
	~Controller() {}

	std::vector<User> getUsers() { return repo->getUsers(); }
	std::vector<Question> getQuestions() { return repo->getQuestions(); }
	std::vector<Answer> getAnswers() { return repo->getAnswers(); }

	void addQuestion(int id, std::string t, std::string n,int ans)
	{
		this->repo->addQuestion(id, t, n,ans);
		this->notify();
	}
	void addAnswer(int id, int qid, std::string n, std::string t, int v)
	{
		this->repo->addAnswer(id, qid, n, t, v);
		this->notify();
	}

	std::vector<Question> searchQuestion(std::string text)
	{
		return repo->searchQuestion(text);
	}

	std::vector<Answer> getAnswer(int qid)
	{
		return repo->getAnswer(qid);
	}

};