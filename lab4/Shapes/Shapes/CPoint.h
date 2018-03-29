#pragma once
#include "longArithmetic.h"

class CPoint final
{
public:
	CPoint() = default;

	CPoint(std::string & x0, std::string & y0);

	std::string ToString() const;

	bool operator==(const CPoint & point) const;
	bool operator!=(const CPoint & point) const;

	CLongNumber x = CLongNumber(0);
	CLongNumber y = CLongNumber(0);
};