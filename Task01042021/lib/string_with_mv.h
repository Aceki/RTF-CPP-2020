#pragma once

#include <stdexcept>
#include <iostream>

class StringWithMove
{
public:
	StringWithMove(const char* cstr);

	StringWithMove() : StringWithMove("") { }

	StringWithMove(const StringWithMove& obj) : StringWithMove(obj.m_cstr) { }

    StringWithMove(StringWithMove&&);

	bool equals(const char*) const;

	bool equals(const StringWithMove&) const;

	bool isEmpty() const;

	int length() const;

	char at(int) const;

	char operator[](int index) const;

	StringWithMove operator+(const char*) const;

	StringWithMove operator+(const StringWithMove&) const;

	StringWithMove& operator+=(const char*);

	StringWithMove& operator+=(const StringWithMove&);

	StringWithMove& operator=(const char*);

	StringWithMove& operator=(const StringWithMove&);

    StringWithMove& operator=(StringWithMove&&);

	~StringWithMove();

	friend std::ostream& operator<<(std::ostream& os, const StringWithMove& str);
private:
	char* m_cstr;
	int m_length;
};

inline bool StringWithMove::isEmpty() const { return m_length == 0; }

inline int StringWithMove::length() const { return m_length; }

inline char StringWithMove::at(int index) const
{
	if (index < 0 || index >= m_length)
		throw std::out_of_range("Index is out of range!");

	return m_cstr[index];
}

inline char StringWithMove::operator[](int index) const { return m_cstr[index]; }

std::ostream& operator<<(std::ostream& os, const StringWithMove& str);

