#pragma once

#include <string>

class Coordinates
{
private:
	int ra;
	int dec;

public:
	Coordinates(int ra, int dec) :ra(ra), dec(dec) {}
	~Coordinates() {}

	int getRa() { return this->ra; }
	int getDec() { return this->dec; }
	void setRa(int ra) { this->ra = ra; }
	void setDec(int dec) { this->dec = dec; }
};


class Star
{
private:
	std::string name;
	std::string constellation;
	Coordinates coords;
	int diameter;

public:
	Star(std::string name, std::string constellation, Coordinates coords, int diameter) :
		name(name), constellation(constellation), coords(coords), diameter(diameter) {}
	~Star() {}

	std::string getName() { return this->name; }
	std::string getConst() { return this->constellation; }
	Coordinates getCoords() { return this->coords; }
	int getDiameter() { return this->diameter; }




};