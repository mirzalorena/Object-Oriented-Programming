#include "Repo.h"

#include <fstream>

Repo::Repo()
{
	this->readData();
}

void Repo::readData()
{
	//read drivers
	std::ifstream din("d.txt");
	std::string name;
	std::string l1;
	getline(din, l1, '#');
	int status, lat, lon, score;
	int c1 = 0;
	c1++;
	while (l1 != "")
	{
		if (c1 == 1)
			name = l1;
		if (c1 == 2)
			status = stoi(l1);
		if (c1 == 3)
			lat = stoi(l1);
		if (c1 == 4)
			lon = stoi(l1);
		if (c1 == 5)
		{
			score = stoi(l1);
			c1 = 0;
			this->addDriver(name, status, lat, lon, score);
			getline(din, l1);
		}
		getline(din, l1, '#');
		c1++;
	}

	//read reports
	std::ifstream rin("r.txt");
	std::string descr, report;
	std::string l2;
	getline(rin, l2, '#');
	int lat2, lon2, valid;
	int c2 = 0;
	c2++;
	while (l2 != "")
	{
		if (c2 == 1)
			descr = l2;
		if (c2 == 2)
			report = l2;
		if (c2 == 3)
			lat2 = stoi(l2);
		if (c2 == 4)
			lon2 = stoi(l2);
		if (c2 == 5)
		{
			valid = stoi(l2);
			c2 = 0;
			this->addReport(descr, report, lat2, lon2, valid);
			getline(rin, l2);
		}
		getline(rin, l2, '#');
		c2++;
	}

}