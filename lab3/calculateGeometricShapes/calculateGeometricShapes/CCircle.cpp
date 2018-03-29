#include "stdafx.h"
#include "CCircle.h"

CCircle::CCircle(const string &type, CPoint center, double radius)
	: CShape(type)
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return (M_PI * m_radius * m_radius);
}

double CCircle::GetPerimeter() const
{
	return (2 * M_PI * m_radius);
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::AppendProperties(ostream & strm) const
{
	strm << "\nRadius = " << m_radius
		<< "\nCenter = " << m_center.ToString();
}