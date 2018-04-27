#include "stdafx.h"
#include "CCircle.h"

CCircle::CCircle(const std::string & type, CPoint center, const CLongNumber & radius)
	: CShape(type)
	, m_center(center)
	, m_radius(radius)
{
}

CLongNumber CCircle::GetArea() const
{
	return (CLongNumber(PI) * m_radius * m_radius) / 100;
}

CLongNumber CCircle::GetPerimeter() const
{
	return (2 * CLongNumber(PI) * m_radius) / 100;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

CLongNumber CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::Accept(IShapeVisitor & v) const
{
	v.Visit(*this);
}

void CCircle::AppendProperties(std::ostream & strm) const
{
	strm << "\nRadius = " << m_radius
		<< "\nCenter = " << m_center.ToString();
}