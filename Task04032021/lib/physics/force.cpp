#include "force.h"
#include "logic_exception.h"
#include "not_implemented_exception.h"

Physics::Force Physics::Force::operator+(const PhysicalQuantity& quantity) const
{
    if(const Force* forcePtr = dynamic_cast<const Force*>(&quantity))
        return Force(m_value + forcePtr->m_value);
    throw LogicException();
} 

Physics::Force Physics::Force::operator-(const PhysicalQuantity& quantity) const
{
    if(const Force* forcePtr = dynamic_cast<const Force*>(&quantity))
        return Force(m_value - forcePtr->m_value);
    throw LogicException();
}

Physics::Force Physics::Force::operator*(const PhysicalQuantity& quantity) const
{
    throw NotImplementedException();
} 

Physics::Force Physics::Force::operator/(const PhysicalQuantity& quantity) const
{
    throw NotImplementedException();
} 

Physics::Force& Physics::Force::operator+=(const PhysicalQuantity& quantity)
{
    if(const Force* forcePtr = dynamic_cast<const Force*>(&quantity))
    {
        m_value += forcePtr->m_value;

        return *this;
    }
    throw LogicException();
}

Physics::Force& Physics::Force::operator-=(const PhysicalQuantity& quantity)
{
    if(const Force* forcePtr = dynamic_cast<const Force*>(&quantity))
    {
        m_value -= forcePtr->m_value;

        return *this;
    }
    throw LogicException();
}

Physics::Force& Physics::Force::operator*=(const PhysicalQuantity& quantity)
{
    throw NotImplementedException();
}

Physics::Force& Physics::Force::operator/=(const PhysicalQuantity& quantity)
{
    throw NotImplementedException();
}
