#pragma once

#include "exception.h"

class NotImplementedException : public Exception
{
public:
	NotImplementedException() : Exception("Not implemented exception!") { }
};