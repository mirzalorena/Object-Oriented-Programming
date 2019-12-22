#pragma once

#include "Repo.h"
#include "Subject.h"
#include <assert.h>

class Controller : public Subject
{
private:
	Repo * repo;

public:
	Controller(Repo*repo):repo(repo) {}
	~Controller() {}

	std::vector<Ethnologist> getEth() { return repo->getEth(); }
	std::vector<Building> getBuildings() { return repo->getBuildings(); }

	Building getBuildingByIndex(int index)
	{
		return repo->getBuildingByIndex(index);
	}

	bool cmp(Building a, Building b)
	{
		return a.getThematicSector() < b.getThematicSector();
	}

	std::vector<Building> sort(std::vector<Building> list, std::string s)
	{
		/*
		Function that sorts a given list by the thematic sector. The first in the list will be the items with the corresponding sector, followed by
		the rest, sorted;
		input: list, string sector;
		output: the list sorted accordingly
		*/

		std::vector<Building> result;
		int index = -1;
		for (auto i : list)
		{
			index++;
			if (i.getThematicSector() == s)
			{
				result.push_back(i);
				list.erase(list.begin() + index);
			}
		}
		for (auto j : list)
		{
			result.push_back(j);
		}
		return result;
	}

	/*std::vector<Building> sortBySector(std::string s)
	{
		
		Function which sorts the list by the thematic sector. The buildings with the given sector will be first, follwed by the others
		sorted.
		input: string sector;
		output: the sorted list;
		
		std::vector<Building> all = this->repo->getBuildings();
		std::vector<Building> result;
		//sort(all.begin(),all.end(), cmp);
		int index = -1;
		for (auto i : all)
		{
			index++;
			if (i.getThematicSector() == s)
			{
				result.push_back(i);
				all.erase(all.begin() + index);
			}
			
		}
		for (auto j : all) {
			result.push_back(j);
		}
		return result;
	

	}*/

	void addBuilding(int id, std::string descr, int year, std::string sector, int x, int y)
	{
		/*
		Function which adds a building to the repository;
		input: int id, string description,int year, string sector, int x, int y
		output: nothing(void) -----new building is added to the repository
		*all the other observers are notified*
		*/

		this->repo->addBuilding(id, descr, year, sector, x, y);
		this->notify();
	}

	void update(int poz, int id, std::string descr, int year, int x, int y)
	{
		this->repo->update(poz, id, descr, year, x, y);
		this->notify();
	}

	int getDistance(int x1, int y1, int x2, int y2)
	{
		return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	}

	int getAverageDistance(std::string sector, int x, int y)
	{
		int sum = 0;
		std::vector<Building> list;
		
		for (auto i : repo->getBuildings())
		{
			if (i.getThematicSector() == sector)
				list.push_back(i);
		}
		for (auto j : list)
		{
			sum = sum + getDistance(x, y, j.getLocation().getX(), j.getLocation().getY());
		}
		if (list.size() == 0)
			return 0;
		int average = sum / list.size();
		return average;

	}

	void tests()
	{
		std::vector<Building> list = this->repo->getBuildings();
		this->addBuilding(7, "8", 6, "9", 7, 8);
		assert(list.size() == 3);

		std::vector<Building> list2;
		list2.push_back(Building(1, "1", 1, "da", Location(1,4)));
		list2.push_back(Building(2, "2", 2, "da", Location(2, 5)));
		list2.push_back(Building(3, "3", 3, "aaa", Location(3, 6)));
		std::vector<Building> sorted = sort(list2, "da");
		assert(sorted[0].getId() == 1);
		assert(sorted[2].getYear() == 3);


	}


};