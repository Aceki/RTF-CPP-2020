#include <ios>

#include "complex.h"

Complex Complex::operator+(const Complex& number) const
{
	return Complex(m_real + number.m_real, m_imaginary + number.m_imaginary);
}

Complex Complex::operator-(const Complex& number) const
{
	return Complex(m_real - number.m_real, m_imaginary - number.m_imaginary);
}

Complex Complex::operator*(const Complex& number) const
{
	return Complex(m_real * number.m_real - m_imaginary * number.m_imaginary, 
				   m_imaginary * number.m_real + m_real * number.m_imaginary);
}

std::ostream& operator<<(std::ostream& os, const Complex& number)
{
	return (os << number.real() << std::showpos << number.imaginary() << 'i');
}
