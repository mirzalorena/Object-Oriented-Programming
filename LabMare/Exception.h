#pragma once
#include <string>

class FileException : public std::exception
{
protected:
	std::string message;

public:
	FileException(const std::string& msg);
	virtual const char* what();

};



class Exception : public std::exception
{
private:
	std::string message;
public:
	Exception(const std::string &message);
	std::string get_message();
	~Exception();
};



