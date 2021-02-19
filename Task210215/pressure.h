#pragma once

#include "physical_quantity.h"

namespace Physics
{
	struct Pressure : PhysicalQuantity
	{
	public:
		Pressure(double value) : PhysicalQuantity(value, "Pa") { }

		Pressure operator+(const Pressure& pressure) const;

		Pressure operator-(const Pressure& pressure) const;

		Pressure operator*(const Pressure& pressure) const;

		Pressure operator/(const Pressure& pressure) const;
	};
}
