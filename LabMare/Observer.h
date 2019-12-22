#pragma once
#include <vector>

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	std::vector<Observer*> obeservers;

public:
	void addObserver(Observer* obs)
	{
		this->obeservers.push_back(obs);
	}
	void notify()
	{
		for (auto obs : this->obeservers)
			obs->update();
	}

};