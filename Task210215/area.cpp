#include "area.h"

Physics::Area Physics::Area::operator+(const Area& area) const
{
	return Area(value() + area.value());
}

Physics::Area Physics::Area::operator-(const Area& area) const
{
	return Area(value() - area.value());
}


Physics::Area Physics::Area::operator*(const Area& area) const
{
	return Area(value() * area.value());
}

Physics::Area Physics::Area::operator/(const Area& area) const
{
	return Area(value() / area.value());
}

