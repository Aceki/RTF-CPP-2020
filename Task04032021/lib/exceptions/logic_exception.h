#pragma once

#include "exception.h"

class LogicException : public Exception
{
public:
	LogicException() : Exception("Logic exception!") { }
};

