#include "physical_quantity.h"

std::ostream& Physics::operator<<(std::ostream& os, const PhysicalQuantity& quantity)
{
	return (os << quantity.m_value << ' ' << quantity.m_sign);
}

Physics::PhysicalQuantity Physics::PhysicalQuantity::operator+(const PhysicalQuantity& quantity)
{
	return PhysicalQuantity(value() + quantity.value(), "?");
}

Physics::PhysicalQuantity Physics::PhysicalQuantity::operator-(const PhysicalQuantity& quantity)
{
	return PhysicalQuantity(value() - quantity.value(), "?");
}

Physics::PhysicalQuantity Physics::PhysicalQuantity::operator*(const PhysicalQuantity& quantity)
{
	return PhysicalQuantity(value() * quantity.value(), "?");
}

Physics::PhysicalQuantity Physics::PhysicalQuantity::operator/(const PhysicalQuantity& quantity)
{
	return PhysicalQuantity(value() / quantity.value(), "?");
}
