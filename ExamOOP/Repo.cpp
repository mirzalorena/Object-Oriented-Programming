#include "Repo.h"

#include <fstream>

Repo::Repo()
{
	this->readData();
	//ethnologists.push_back(Ethnologist("Ionel", "lala"));
}

void Repo::readData()
{
	//read ethnologists
	std::ifstream ein("e.txt");
	std::string name, sector;
	std::string l1;
	getline(ein, l1, '#');
	int c1 = 0;
	c1++;
	while (l1 != "")
	{
		if (c1 == 1)
			name = l1;
		if (c1 == 2)
		{
			sector = l1;
			c1 = 0;
			this->addEth(name, sector);
			getline(ein, l1);
		}
		c1++;
		getline(ein, l1, '#');
	}

	//read buildings
	std::ifstream bin("b.txt");
	std::string descr, sector2;
	std::string l2;
	getline(bin, l2, '#');
	int id, year, x, y;
	int c2 = 0;
	c2++;
	while (l2 != "")
	{
		if (c2 == 1)
			id = stoi(l2);
		if (c2 == 2)
			descr = l2;
		if (c2 == 3)
			year = stoi(l2);
		if (c2 == 4)
			sector2 = l2;
		if (c2 == 5)
			x = stoi(l2);
		if (c2 == 6)
		{
			y = stoi(l2);
			c2 = 0;
			this->addBuilding(id, descr, year, sector2, x, y);
			getline(bin, l2);
		}
		c2++;
		getline(bin, l2, '#');
	}

}