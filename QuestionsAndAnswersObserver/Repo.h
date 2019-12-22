#pragma once

#include "User.h"
#include "Question.h"
#include "Answer.h"

#include <vector>

class Repo
{
private:
	std::vector<User> users;
	std::vector<Question> questions;
	std::vector<Answer> answers;

public:
	Repo();
	~Repo() {}

	void readData();

	std::vector<User> getUsers() { return this->users; }
	std::vector<Question> getQuestions() { return this->questions; }
	std::vector<Answer> getAnswers() { return this->answers; }

	void addUser(std::string name)
	{
		this->users.push_back(User(name));
	}
	void addQuestion(int id, std::string t, std::string n,int ans)
	{
		this->questions.push_back(Question(id, t, n,ans));
	}
	void addAnswer(int id, int idq, std::string n, std::string t, int v)
	{
		this->answers.push_back(Answer(id, idq, n, t, v));
	}

	std::vector<Question> searchQuestion(std::string text)
	{
		std::vector<Question> result;
		for (auto i : questions)
		{
			if (i.getText() == text)
				result.push_back(i);

		}
		return result;
	}

	std::vector<Answer> getAnswer(int qid)
	{
		std::vector<Answer> result;
		for (auto i : answers)
		{
			if (i.getIdQ() == qid)
				result.push_back(i);
		}
		return result;

	}

};