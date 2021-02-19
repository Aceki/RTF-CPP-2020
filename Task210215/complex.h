#pragma once

#include <iostream>

struct Complex
{
public:
	Complex(int real = 0, int imaginary = 0) : m_real(real), m_imaginary(imaginary) { }

	static Complex zero() { return Complex(0); }

	int real() const { return m_real; }

	int imaginary() const { return m_imaginary; }

	Complex conjugation() const { return Complex(m_real, -m_imaginary); }

	Complex operator+(const Complex& number) const;

	Complex operator-(const Complex& number) const;

	Complex operator*(const Complex& number) const;
private:
	const int m_real;
	const int m_imaginary;
};

std::ostream& operator<<(std::ostream& os, const Complex& number);

