#pragma once

class Amperage
{
public:
	explicit Amperage(double value) : m_value(value) { }

	double value() const;
private:
	double m_value;
};



