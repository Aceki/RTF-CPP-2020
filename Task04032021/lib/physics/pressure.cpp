#include "pressure.h"
#include "logic_exception.h"

Physics::Pressure Physics::Pressure::operator+(const PhysicalQuantity& quantity) const
{
    if(const Pressure* PressurePtr = dynamic_cast<const Pressure*>(&quantity))
        return Pressure(m_value + PressurePtr->m_value);
    throw new LogicException();
} 

Physics::Pressure Physics::Pressure::operator-(const PhysicalQuantity& quantity) const
{
    if(const Pressure* PressurePtr = dynamic_cast<const Pressure*>(&quantity))
        return Pressure(m_value - PressurePtr->m_value);
    throw new LogicException();
} 

Physics::Pressure& Physics::Pressure::operator+=(const PhysicalQuantity& quantity)
{
    if(const Pressure* PressurePtr = dynamic_cast<const Pressure*>(&quantity))
    {
        m_value += PressurePtr->m_value;

        return *this;
    }
    throw new LogicException();
}

Physics::Pressure& Physics::Pressure::operator-=(const PhysicalQuantity& quantity)
{
    if(const Pressure* PressurePtr = dynamic_cast<const Pressure*>(&quantity))
    {
        m_value -= PressurePtr->m_value;

        return *this;
    }
    throw new LogicException();
} 