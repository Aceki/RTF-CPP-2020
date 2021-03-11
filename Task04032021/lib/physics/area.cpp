#include "area.h"
#include "logic_exception.h"

Physics::Area Physics::Area::operator+(const PhysicalQuantity& quantity) const
{
    if(const Area* areaPtr = dynamic_cast<const Area*>(&quantity))
        return Area(m_value + areaPtr->m_value);
    throw new LogicException();
} 

Physics::Area Physics::Area::operator-(const PhysicalQuantity& quantity) const
{
    if(const Area* areaPtr = dynamic_cast<const Area*>(&quantity))
        return Area(m_value - areaPtr->m_value);
    throw new LogicException();
} 

Physics::Area& Physics::Area::operator+=(const PhysicalQuantity& quantity)
{
    if(const Area* areaPtr = dynamic_cast<const Area*>(&quantity))
    {
        m_value += areaPtr->m_value;

        return *this;
    }
    throw new LogicException();
}

Physics::Area& Physics::Area::operator-=(const PhysicalQuantity& quantity)
{
    if(const Area* areaPtr = dynamic_cast<const Area*>(&quantity))
    {
        m_value -= areaPtr->m_value;

        return *this;
    }
    throw new LogicException();
} 