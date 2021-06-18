#pragma once

#include <stdexcept>
#include <iostream>

class StringWithoutMove
{
public:
	StringWithoutMove(const char* cstr);

	StringWithoutMove() : StringWithoutMove("") { }

	StringWithoutMove(const StringWithoutMove& obj) : StringWithoutMove(obj.m_cstr) { }

	bool equals(const char*) const;

	bool equals(const StringWithoutMove&) const;

	bool isEmpty() const;

	int length() const;

	char at(int) const;

	char operator[](int index) const;

	StringWithoutMove operator+(const char*) const;

	StringWithoutMove operator+(const StringWithoutMove&) const;

	StringWithoutMove& operator+=(const char*);

	StringWithoutMove& operator+=(const StringWithoutMove&);

	StringWithoutMove& operator=(const char*);

	StringWithoutMove& operator=(const StringWithoutMove&);

	~StringWithoutMove();

	friend std::ostream& operator<<(std::ostream& os, const StringWithoutMove& str);
private:
	char* m_cstr;
	int m_length;
};

inline bool StringWithoutMove::isEmpty() const { return m_length == 0; }

inline int StringWithoutMove::length() const { return m_length; }

inline char StringWithoutMove::at(int index) const
{
	if (index < 0 || index >= m_length)
		throw std::out_of_range("Index is out of range!");

	return m_cstr[index];
}

inline char StringWithoutMove::operator[](int index) const { return m_cstr[index]; }

std::ostream& operator<<(std::ostream& os, const StringWithoutMove& str);

