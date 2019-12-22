#pragma once

#include "Driver.h"
#include "Report.h"

class Repo
{
private:
	std::vector<Driver> drivers;
	std::vector<Report> reports;

public:
	Repo();
	~Repo() {}

	void readData();

	std::vector<Driver> getDrivers() { return this->drivers; }
	std::vector<Report> getReports() { return this->reports; }

	void addDriver(std::string n, int s, int lat, int lon, int score)
	{
		this->drivers.push_back(Driver(n, s, Location(lat, lon), score));
	}
	void addReport(std::string d, std::string r, int lat, int lon, int v)
	{
		this->reports.push_back(Report(d, r, Location(lat, lon), v));
	}



};