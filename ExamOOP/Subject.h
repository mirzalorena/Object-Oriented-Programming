#pragma once

#include<vector>
#include "Observer.h"

class Subject
{
private:
	std::vector<Observer*> obs;

public:
	Subject() {}
	~Subject() {}

	void notify()
	{
		for (auto o : obs)
		{
			o->update();
		}
	}
	void registerObserver(Observer*o)
	{
		this->obs.push_back(o);
	}


};