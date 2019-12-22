#include "Repo.h"

#include <fstream>

Repo::Repo()
{
	this->readData();
}

void Repo::readData()
{
	//read programmers
	std::ifstream pin("p.txt");
	std::string name;
	std::string l1;
	int id;
	getline(pin, l1, '#');
	int c1 = 0;
	c1++;
	while (l1 != "")
	{
		if (c1 == 1)
			name = l1;
		if (c1 == 2)
		{
			id = stoi(l1);
			c1 = 0;
			this->addProgrammer(name, id);
			getline(pin, l1);
		}
		getline(pin, l1, '#');
		c1++;
	}

	//read tasks
	std::ifstream tin("t.txt");
	std::string descr;
	std::string l2;
	int status, idt;
	getline(tin, l2, '#');
	int c2 = 0;
	c2++;
	while (l2 != "")
	{
		if (c2 == 1)
			descr = l2;
		if (c2 == 2)
			status = stoi(l2);
		if (c2 == 3)
		{
			idt = stoi(l2);
			c2 = 0;
			this->addTask(descr, status, idt);
			getline(tin, l2);
		}
		getline(tin, l2, '#');
		c2++;
	}


}