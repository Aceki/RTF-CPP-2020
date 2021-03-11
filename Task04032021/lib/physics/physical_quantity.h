#pragma once

#include <iostream>

namespace Physics
{
	class PhysicalQuantity
	{
	public:
		virtual double value() const = 0;

		virtual std::string sign() const = 0;
	};

	std::ostream& operator<<(std::ostream& os, const PhysicalQuantity& quantity);
}

