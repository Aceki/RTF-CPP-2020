#include "pressure.h"

Physics::Pressure Physics::Pressure::operator+(const Pressure& pressure) const
{
	return Pressure(value() + pressure.value());
}

Physics::Pressure Physics::Pressure::operator-(const Pressure& pressure) const
{
	return Pressure(value() - pressure.value());
}

Physics::Pressure Physics::Pressure::operator*(const Pressure& pressure) const
{
	return Pressure(value() * pressure.value());
}

Physics::Pressure Physics::Pressure::operator/(const Pressure& pressure) const
{
	return Pressure(value() / pressure.value());
}
