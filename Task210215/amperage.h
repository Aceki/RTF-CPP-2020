#pragma once

class Amperage
{
public:
	explicit Amperage(double value) : m_value(value) { }

	double value();
private:
	int m_readCount = 0;

	double m_value;
};



