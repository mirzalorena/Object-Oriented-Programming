#include "Repo.h"

#include <fstream>

Repo::Repo()
{
	this->readData();
}

void Repo::readData()
{
	//read users;
	std::ifstream uin("u.txt");
	std::string name;
	std::string l1;
	getline(uin, l1, '#');
	int c1 = 0;
	c1++;
	while (l1 != "")
	{
		if (c1 == 1)
		{
			name = l1;
			c1 = 0;
			this->addUser(name);
			getline(uin, l1);
		}
		getline(uin, l1, '#');
		c1++;
	}

	//read questions;
	std::ifstream qin("q.txt");
	std::string text, nameq;
	std::string l2;
	getline(qin, l2, '#');
	int id,ans;
	int c2 = 0;
	c2++;
	while (l2 != "")
	{
		if (c2 == 1)
			id = stoi(l2);
		if (c2 == 2)
			text = l2;
		if (c2 == 3)
		{
			nameq = l2;
			/*c2 = 0;
			this->addQuestion(id, text, nameq);
			getline(qin, l2);*/
		}
		if (c2 == 4)
		{
			ans = stoi(l2);
			c2 = 0;
			this->addQuestion(id, text, nameq,ans);
			getline(qin, l2);
		}
		getline(qin, l2, '#');
		c2++;
	}

	//read answers
	std::ifstream ain("a.txt");
	std::string namea, texta;
	std::string l3;
	getline(ain, l3, '#');
	int ida, idq, v;
	int c3 = 0;
	c3++;
	while (l3 != "")
	{
		if (c3 == 1)
			ida = stoi(l3);
		if (c3 == 2)
			idq == stoi(l3);
		if (c3 == 3)
			namea = l3;
		if (c3 == 4)
			texta = l3;
		if (c3 == 5)
		{
			v = stoi(l3);
			c3 = 0;
			this->addAnswer(ida, idq, namea, texta, v);
			getline(ain, l3);
		}
		getline(ain, l3, '#');
		c3++;
	}


}