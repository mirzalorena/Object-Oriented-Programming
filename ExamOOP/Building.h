#pragma once

#include <string>
#include <vector>

class Location
{
private:
	int x;
	int y;

public:
	Location(int x, int y) :x(x), y(y) {}
	~Location() {}

	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

};

class Building
{
private:
	int id;
	std::string description;
	int year;
	std::string thematicSector;
	Location location;

public:
	Building(int id, std::string description, int year, std::string thematicSector, Location location) :id(id), description(description), year(year),
		thematicSector(thematicSector), location(location) {}
	~Building() { }

	int getId() { return this->id; }
	std::string getDescription() { return this->description; }
	int getYear() { return this->year; }
	std::string getThematicSector() { return this->thematicSector; }
	Location getLocation() { return this->location; }

	void setId(int id) { this->id = id; }
	void setDescr(std::string d) { this->description = d; }
	void setYear(int year) { this->year = year; }
	void setX(int x) { this->location.setX(x); }
	void setY(int y) { this->location.setY(y); }



};