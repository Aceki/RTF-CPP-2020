#pragma once

#include "physical_quantity.h"

namespace Physics
{
	struct Area : public PhysicalQuantity
	{
	public:
		explicit Area(double value) : PhysicalQuantity(value, "M2") { }

		Area operator+(const Area& area) const;

		Area operator-(const Area& area) const;

		Area operator*(const Area& area) const;

		Area operator/(const Area& area) const;
	};
}

