#pragma once

#include "physical_quantity.h"

namespace Physics
{
    class Force : public PhysicalQuantity
    {
    public:
        Force() = default;

        Force(double value) : m_value(value) { }

        virtual double value() const final { return m_value; }

        virtual std::string sign() const final { return "N"; }

        Force operator+(const PhysicalQuantity& quantity) const;

		Force operator-(const PhysicalQuantity& quantity) const;

		Force operator*(const PhysicalQuantity& quantity) const;

		Force operator/(const PhysicalQuantity& quantity) const;

		Force& operator+=(const PhysicalQuantity& quantity);

		Force& operator-=(const PhysicalQuantity& quantity);

		Force& operator*=(const PhysicalQuantity& quantity);

		Force& operator/=(const PhysicalQuantity& quantity);
    private:
        double m_value = 0;
    };
}