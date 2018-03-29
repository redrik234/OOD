#pragma once
#include "longArithmetic.h"
class IShape
{
public:
	virtual CLongNumber GetPerimeter() const = 0;
	virtual CLongNumber GetArea() const = 0;
	virtual std::string ToString() const = 0;
	virtual ~IShape() = default;
};