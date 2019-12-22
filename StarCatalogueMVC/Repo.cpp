#include "Repo.h"

#include <fstream>

Repo::Repo()
{
	this->readData();
}

void Repo::readData()
{
	//read astronomers
	std::ifstream ain("a.txt");
	std::string name, constel;
	std::string l1;
	getline(ain, l1, '#');
	int c1 = 0;
	c1++;
	while (l1 != "")
	{
		if (c1 == 1)
			name = l1;
		if (c1 == 2)
		{
			constel = l1;
			c1 = 0;
			this->addAstronomer(name, constel);
			getline(ain, l1);
		}
		getline(ain, l1, '#');
		c1++;
	}

	//read stars
	std::ifstream sin("s.txt");
	std::string sname, sconst;
	std::string l2;
	getline(sin, l2, '#');
	int ra, dec, d;
	int c2 = 0;
	c2++;
	while (l2 != "")
	{
		if (c2 == 1)
			sname = l2;
		if (c2 == 2)
			sconst = l2;
		if (c2 == 3)
			ra = stoi(l2);
		if (c2 == 4)
			dec = stoi(l2);
		if (c2 == 5)
		{
			d = stoi(l2);
			c2 = 0;
			this->addStar(sname, sconst, ra, dec, d);
			getline(sin, l2);

		}
		getline(sin, l2, '#');
		c2++;
	}


}