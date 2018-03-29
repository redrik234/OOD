#include "stdafx.h"
#include "CPoint.h"




CPoint::CPoint(std::string & x0, std::string & y0)
{
	x = CLongNumber(x0);
	y = CLongNumber(y0);
}

std::string CPoint::ToString() const
{
	
	return x.ToString() + " " + y.ToString();
}

bool CPoint::operator==(const CPoint & point) const
{
	return ((x == point.x) && (y == point.y));
}

bool CPoint::operator!=(const CPoint & point) const
{
	return !(*this == point);
}