#pragma once

#include <exception>
#include <iostream>
#include <string>

class Exception : public std::exception
{
public:
	virtual std::string what() final { return m_message + m_submessage; }
protected:
	Exception(std::string submessage) : m_submessage(submessage) { };
private:
	std::string m_message = "Exception was occured with message: ";
	std::string m_submessage;
};

