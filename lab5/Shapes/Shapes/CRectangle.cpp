#include "stdafx.h"
#include "CRectangle.h"

CRectangle::CRectangle(const std::string & type, CPoint leftTopPoint, CPoint rightBottomPoint)
	: CShape(type)
	, m_leftTop(leftTopPoint)
	, m_rightButtom(rightBottomPoint)
{
	m_width = GetWidth();
	m_height = GetHeight();
}

CLongNumber CRectangle::GetArea() const
{
	return m_width * m_height;
}

CLongNumber CRectangle::GetPerimeter() const
{
	return (2 * (m_width + m_height));
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightButtom;
}

CLongNumber CRectangle::GetWidth() const
{
	return m_rightButtom.x - m_leftTop.x;
}

CLongNumber CRectangle::GetHeight() const
{
	return m_rightButtom.y - m_leftTop.y;
}

void CRectangle::Accept(IShapeVisitor & v) const
{
	v.Visit(*this);
}

void CRectangle::AppendProperties(std::ostream & strm) const
{
	strm << "\nWidth = " << m_width
		<< "\nHeight = " << m_height;
}