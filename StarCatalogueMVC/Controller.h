#pragma once

#include "Repo.h"

class Controller
{
private:
	Repo * repo;

public:
	Controller(Repo* repo) :repo(repo) {}
	~Controller() {}

	std::vector<Astronomer> getAstronomers()
	{
		return repo->getAstronomers();
	}
	std::vector<Star> getStars()
	{
		return repo->getStars();
	}
	void addStar(std::string n, std::string c, int ra, int dec, int d)
	{
		repo->addStar(n, c, ra, dec, d);
	}
	std::vector<Star> search(std::string n, int ra, int dec)
	{
		return repo->search(n, ra, dec);
	}

};