#pragma once

#include "Ethnologist.h"
#include "Building.h"

class Repo
{
private:
	std::vector<Ethnologist> ethnologists;
	std::vector<Building> buildings;

public:
	Repo();
	~Repo() {}

	void readData();

	std::vector<Ethnologist> getEth() { return this->ethnologists; }
	std::vector<Building> getBuildings() { return this->buildings; }

	Building getBuildingByIndex(int index) { return this->buildings[index]; }

	void addEth(std::string name, std::string sector)
	{
		this->ethnologists.push_back(Ethnologist(name, sector));
	}
	void addBuilding(int id, std::string descr, int year, std::string sector, int x, int y)
	{
		this->buildings.push_back(Building(id, descr, year, sector, Location(x, y)));
	}
	void update(int poz, int id, std::string descr, int year, int x, int y) {
		buildings[poz].setId(id);
		buildings[poz].setDescr(descr);
		buildings[poz].setYear(year);
		buildings[poz].setX(x);
		buildings[poz].setY(y);
	}


};