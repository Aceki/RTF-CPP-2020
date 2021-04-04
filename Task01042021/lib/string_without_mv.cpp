#include <cstring>

#include "string_without_mv.h"

StringWithoutMove::StringWithoutMove(const char* cstr)
{
	m_length = std::strlen(cstr);

	m_cstr = new char[m_length + 1];

	std::strcpy(m_cstr, cstr);
}

bool StringWithoutMove::equals(const char* cstr) const
{
	if (m_length != std::strlen(cstr))
		return false;

	for (int i = 0; i < m_length; i++)
		if (m_cstr[i] != cstr[i])
			return false;
	
	return true;
}

bool StringWithoutMove::equals(const StringWithoutMove& obj) const
{
	return this->equals(obj.m_cstr); 
}

StringWithoutMove StringWithoutMove::operator+(const char* cstr) const
{
	char* m_cstr_concat = new char[m_length + std::strlen(cstr) + 1];

	std::strcpy(m_cstr_concat, m_cstr);
	std::strcat(m_cstr_concat, cstr);

	StringWithoutMove result = StringWithoutMove(m_cstr_concat);

	return result;
}

StringWithoutMove StringWithoutMove::operator+(const StringWithoutMove& obj) const
{
	return *this + obj.m_cstr;
}

StringWithoutMove& StringWithoutMove::operator+=(const char* cstr)
{
	int m_length_concat = m_length + std::strlen(cstr);
	char* m_cstr_concat = new char[m_length_concat + 1];

	std::strcpy(m_cstr_concat, m_cstr);
	std::strcat(m_cstr_concat, cstr);

	delete[] m_cstr;

	m_length = m_length_concat;
	m_cstr = m_cstr_concat;

	return *this;
}

StringWithoutMove& StringWithoutMove::operator+=(const StringWithoutMove& obj)
{
	return *this += obj.m_cstr;
}

StringWithoutMove& StringWithoutMove::operator=(const char* cstr)
{
	if (m_cstr != cstr) 
	{
		delete[] m_cstr;

		m_length = std::strlen(cstr);
		m_cstr = new char[m_length + 1];

		std::strcpy(m_cstr, cstr);
	}

	return *this;
}

StringWithoutMove& StringWithoutMove::operator=(const StringWithoutMove& obj)
{	
	return *this = obj.m_cstr;
}

StringWithoutMove::~StringWithoutMove()
{
	delete[] m_cstr;
}

std::ostream& operator<<(std::ostream& os, const StringWithoutMove& str)
{
	return os << str.m_cstr;
}