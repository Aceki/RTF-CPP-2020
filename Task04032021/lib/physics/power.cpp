#include "power.h"
#include "logic_exception.h"

Physics::Power Physics::Power::operator+(const PhysicalQuantity& quantity) const
{
    if(const Power* PowerPtr = dynamic_cast<const Power*>(&quantity))
        return Power(m_value + PowerPtr->m_value);
    throw new LogicException();
} 

Physics::Power Physics::Power::operator-(const PhysicalQuantity& quantity) const
{
    if(const Power* PowerPtr = dynamic_cast<const Power*>(&quantity))
        return Power(m_value - PowerPtr->m_value);
    throw new LogicException();
}

Physics::Power Physics::Power::operator*(const PhysicalQuantity& quantity) const
{
    throw new LogicException();
} 

Physics::Power Physics::Power::operator/(const PhysicalQuantity& quantity) const
{
    throw new LogicException();
} 

Physics::Power& Physics::Power::operator+=(const PhysicalQuantity& quantity)
{
    if(const Power* PowerPtr = dynamic_cast<const Power*>(&quantity))
    {
        m_value += PowerPtr->m_value;

        return *this;
    }
    throw new LogicException();
}

Physics::Power& Physics::Power::operator-=(const PhysicalQuantity& quantity)
{
    if(const Power* PowerPtr = dynamic_cast<const Power*>(&quantity))
    {
        m_value -= PowerPtr->m_value;

        return *this;
    }
    throw new LogicException();
}

Physics::Power& Physics::Power::operator*=(const PhysicalQuantity& quantity)
{
    throw new LogicException();
}

Physics::Power& Physics::Power::operator/=(const PhysicalQuantity& quantity)
{
    throw new LogicException();
}
