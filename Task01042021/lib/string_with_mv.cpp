#include <cstring>

#include "string_with_mv.h"

StringWithMove::StringWithMove(const char* cstr)
{
	m_length = std::strlen(cstr);

	m_cstr = new char[m_length + 1];

	std::strcpy(m_cstr, cstr);
}

StringWithMove::StringWithMove(StringWithMove&& obj)
{
    m_length = obj.m_length;

    obj.m_length = 0;

    m_cstr = obj.m_cstr;

    obj.m_cstr = nullptr;
}

bool StringWithMove::equals(const char* cstr) const
{
	if (m_length != std::strlen(cstr))
		return false;

	for (int i = 0; i < m_length; i++)
		if (m_cstr[i] != cstr[i])
			return false;
	
	return true;
}

bool StringWithMove::equals(const StringWithMove& obj) const
{
	return this->equals(obj.m_cstr); 
}

StringWithMove StringWithMove::operator+(const char* cstr) const
{
	char* m_cstr_concat = new char[m_length + std::strlen(cstr) + 1];

	std::strcpy(m_cstr_concat, m_cstr);
	std::strcat(m_cstr_concat, cstr);

	StringWithMove result = StringWithMove(m_cstr_concat);

	return result;
}

StringWithMove StringWithMove::operator+(const StringWithMove& obj) const
{
	return *this + obj.m_cstr;
}

StringWithMove& StringWithMove::operator+=(const char* cstr)
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

StringWithMove& StringWithMove::operator+=(const StringWithMove& obj)
{
	return *this += obj.m_cstr;
}

StringWithMove& StringWithMove::operator=(const char* cstr)
{
	delete[] m_cstr;

	m_length = std::strlen(cstr);
	m_cstr = new char[m_length + 1];

	std::strcpy(m_cstr, cstr);

	return *this;
}

StringWithMove& StringWithMove::operator=(const StringWithMove& obj)
{
	return *this = obj.m_cstr;
}

StringWithMove& StringWithMove::operator=(StringWithMove&& obj)
{
    delete[] m_cstr;

    m_length = obj.m_length;

    obj.m_length = 0;

    m_cstr = obj.m_cstr;

    obj.m_cstr = nullptr;

    return *this;
}

StringWithMove::~StringWithMove()
{
	delete[] m_cstr;
}