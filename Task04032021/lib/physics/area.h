#pragma once

#include "physical_quantity.h"

namespace Physics
{
	class Area : public PhysicalQuantity
	{
	public:
		Area() = default;

		Area(double value) : m_value(value) { }

		virtual double value() const final { return m_value; }

		virtual std::string sign() const final { return "M2"; }

		Area operator+(const PhysicalQuantity& quantity) const;

		Area operator-(const PhysicalQuantity& quantity) const;

		Area operator*(const PhysicalQuantity& quantity) const;

		Area operator/(const PhysicalQuantity& quantity) const;

		Area& operator+=(const PhysicalQuantity& quantity);

		Area& operator-=(const PhysicalQuantity& quantity);

		Area& operator*=(const PhysicalQuantity& quantity);

		Area& operator/=(const PhysicalQuantity& quantity);
	private:
		double m_value = 0;
	};
}
