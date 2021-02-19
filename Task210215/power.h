#pragma once

#include "physical_quantity.h"

namespace Physics
{
	struct Power : public PhysicalQuantity
	{
	public:
		explicit Power(double value) : PhysicalQuantity(value, "N") { }

		Power operator+(const Power& power) const;

		Power operator-(const Power& power) const;

		Power operator*(const Power& power) const;

		Power operator/(const Power& power) const;
	};

}
