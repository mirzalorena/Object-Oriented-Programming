#pragma once

#include"Star.h"
#include "Astronomer.h"
#include <vector>

class Repo
{
private:
	std::vector<Astronomer> astronomers;
	std::vector<Star> stars;

public:
	Repo();
	~Repo() {}

	void readData();

	std::vector<Astronomer> getAstronomers() { return this->astronomers; }
	std::vector<Star> getStars() { return this->stars; }
	int getNrOfStars() { return this->stars.size(); }

	Star getStarByIndex(int index)
	{
		return this->stars[index];
	}

	void addAstronomer(std::string n, std::string c)
	{
		this->astronomers.push_back(Astronomer(n, c));
	}
	void addStar(std::string n, std::string c, int ra, int dec, int d)
	{
		this->stars.push_back(Star(n, c, Coordinates(ra, dec), d));
	}

	std::vector<Star> search(std::string name,int ra,int dec)
	{
		std::vector<Star> list;
		for (auto i : stars)
		{
			if (i.getName() == name || i.getCoords().getRa()==ra || i.getCoords().getDec()==dec)
				list.push_back(i);
		}
		return list;
	}


};