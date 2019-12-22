#include "Exception.h"



FileException::FileException(const std::string& message) :message(message)
{

}

const char* FileException::what()
{
	return message.c_str();
}

Exception::Exception(const std::string &message) :
	message{ message }
{
}

std::string Exception::get_message()
{
	return this->message;
}

Exception::~Exception()
{
}


