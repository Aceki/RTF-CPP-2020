#include "amperage.h"

double Amperage::value()
{
	m_readCount++;

	return m_value;
}
