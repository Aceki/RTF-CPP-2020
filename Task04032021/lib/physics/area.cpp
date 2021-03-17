#include "area.h"
#include "logic_exception.h"
#include "not_implemented_exception.h"

Physics::Area Physics::Area::operator+(const PhysicalQuantity& quantity) const
{
    if(const Area* AreaPtr = dynamic_cast<const Area*>(&quantity))
        return Area(m_value + AreaPtr->m_value);
    throw LogicException();
} 

Physics::Area Physics::Area::operator-(const PhysicalQuantity& quantity) const
{
    if(const Area* AreaPtr = dynamic_cast<const Area*>(&quantity))
        return Area(m_value - AreaPtr->m_value);
    throw LogicException();
}

Physics::Area Physics::Area::operator*(const PhysicalQuantity& quantity) const
{
    throw NotImplementedException();
} 

Physics::Area Physics::Area::operator/(const PhysicalQuantity& quantity) const
{
    throw NotImplementedException();
} 

Physics::Area& Physics::Area::operator+=(const PhysicalQuantity& quantity)
{
    if(const Area* AreaPtr = dynamic_cast<const Area*>(&quantity))
    {
        m_value += AreaPtr->m_value;

        return *this;
    }
    throw LogicException();
}

Physics::Area& Physics::Area::operator-=(const PhysicalQuantity& quantity)
{
    if(const Area* AreaPtr = dynamic_cast<const Area*>(&quantity))
    {
        m_value -= AreaPtr->m_value;

        return *this;
    }
    throw LogicException();
}

Physics::Area& Physics::Area::operator*=(const PhysicalQuantity& quantity)
{
    throw NotImplementedException();
}

Physics::Area& Physics::Area::operator/=(const PhysicalQuantity& quantity)
{
    throw NotImplementedException();
}