#include "amperage.h"

double Amperage::value() const
{
	static int readCount = 0;
	
	readCount++;

	return m_value;
}
