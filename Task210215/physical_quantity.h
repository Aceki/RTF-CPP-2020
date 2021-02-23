#pragma once

#include <iostream>

namespace Physics
{
	class PhysicalQuantity
	{
	public:
		double value() const { return m_value; }

		PhysicalQuantity operator+(const PhysicalQuantity& quantity) const;

		PhysicalQuantity operator-(const PhysicalQuantity& quantity) const;

		PhysicalQuantity operator*(const PhysicalQuantity& quantity) const;

		PhysicalQuantity operator/(const PhysicalQuantity& quantity) const;

		friend std::ostream& operator<<(std::ostream&, const PhysicalQuantity&);
	protected:
		PhysicalQuantity(double value, const char* sign) : m_value(value), m_sign(sign) { }
	private:
		const double m_value;
		const char* m_sign;
	};

	std::ostream& operator<<(std::ostream&, const PhysicalQuantity&);
}
