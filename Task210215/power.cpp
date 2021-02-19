#include "power.h"

Physics::Power Physics::Power::operator+(const Power& power) const
{
	return Power(value() + power.value());
}

Physics::Power Physics::Power::operator-(const Power& power) const
{
	return Power(value() - power.value());
}

Physics::Power Physics::Power::operator*(const Power& power) const
{
	return Power(value() * power.value());
}

Physics::Power Physics::Power::operator/(const Power& power) const
{
	return Power(value() / power.value());
}
