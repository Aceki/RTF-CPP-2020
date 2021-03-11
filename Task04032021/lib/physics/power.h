#pragma once

#include "physical_quantity.h"

namespace Physics
{
    class Power : public PhysicalQuantity
    {
    public:
        Power() = default;

        Power(double value) : m_value(value) { }

        virtual double value() const final { return m_value; }

        virtual std::string sign() const final { return "N"; }

        Power operator+(const PhysicalQuantity& quantity) const;

		Power operator-(const PhysicalQuantity& quantity) const;

		Power& operator+=(const PhysicalQuantity& quantity);

		Power& operator-=(const PhysicalQuantity& quantity);
    private:
        double m_value = 0;
    };
}