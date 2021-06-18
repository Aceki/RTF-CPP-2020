#include "physical_quantity.h"
#include "area.h"

std::ostream& Physics::operator<<(std::ostream& os, const PhysicalQuantity& quantity)
{
    return os << quantity.value() << ' ' << quantity.sign();
}