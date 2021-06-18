#pragma once

#include "physical_quantity.h"

namespace Physics
{
	class Pressure : public PhysicalQuantity
	{
	public:
        Pressure() = default;

		Pressure(double value) : m_value(value) { }

		virtual double value() const final { return m_value; }

		virtual std::string sign() const final { return "M2"; }

		Pressure operator+(const PhysicalQuantity& quantity) const;

		Pressure operator-(const PhysicalQuantity& quantity) const;

		Pressure operator*(const PhysicalQuantity& quantity) const;

		Pressure operator/(const PhysicalQuantity& quantity) const;

		Pressure& operator+=(const PhysicalQuantity& quantity);

		Pressure& operator-=(const PhysicalQuantity& quantity);

		Pressure& operator*=(const PhysicalQuantity& quantity);

		Pressure& operator/=(const PhysicalQuantity& quantity);
	private:
		double m_value = 0;
	};
}
