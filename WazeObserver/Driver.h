#pragma once

#include <string>
#include <vector>

class Location
{
private:
	int latitude;
	int longitude;
public:
	Location(int latitude, int longitude) :
		latitude(latitude), longitude(longitude) {}
	~Location() {}

	int getLatitude() { return this->latitude; }
	int getLongitude() { return this->longitude; }
};

class Driver
{
private:
	std::string name;
	int status;
	Location location;
	int score;

public:
	Driver(std::string name, int status,
		Location location, int score) :name(name),
		status(status), location(location), score(score) {}
	~Driver() { }

	std::string getName() { return this->name; }
	std::string getStatus()
	{
		std::vector<std::string> option = { "baby",
		"regular","advanced" };
		return option[status];
	}
	Location getLocation() { return this->location; }
	int getScore() { return this->score; }

	void setStatus(int status) { this->status = status; }

};