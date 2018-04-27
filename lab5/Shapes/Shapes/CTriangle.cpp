#include "stdafx.h"
#include "CTriangle.h"

CTriangle::CTriangle(const std::string & type, CPoint vertex1, CPoint vertex2, CPoint vertex3)
	:CShape(type)
{
	m_vertices.push_back(vertex1);
	m_vertices.push_back(vertex2);
	m_vertices.push_back(vertex3);
}

CLongNumber GetSideLength(const CPoint & point1, const CPoint & point2)
{
	CLongNumber vectorX;
	CLongNumber vectorY;

	if (point2.x > point1.x)
	{
		vectorX = point2.x - point1.x;
	}
	else
	{
		vectorX = point1.x - point2.x;
	}
	if (point2.y > point1.y)
	{
		vectorY = point2.y - point1.y;
	}
	else
	{
		vectorY = point1.y - point2.y;
	}

	CLongNumber length = sqrt(vectorX * vectorX + vectorY * vectorY);

	return length;
}

CLongNumber CTriangle::GetPerimeter() const
{
	return (GetSideLength(m_vertices[0], m_vertices[1])
		+ GetSideLength(m_vertices[1], m_vertices[2])
		+ GetSideLength(m_vertices[2], m_vertices[0]));
}

CLongNumber CTriangle::GetArea() const
{
	CLongNumber semiperimeter = GetPerimeter() / 2;

	if (semiperimeter + 1 == GetSideLength(m_vertices[0], m_vertices[1]))
	{
		semiperimeter = GetSideLength(m_vertices[0], m_vertices[1]);
	}

	return sqrt(semiperimeter *
		(semiperimeter - GetSideLength(m_vertices[0], m_vertices[1])) *
		(semiperimeter - GetSideLength(m_vertices[1], m_vertices[2])) *
		(semiperimeter - GetSideLength(m_vertices[2], m_vertices[0]))
	);
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertices[0];
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertices[1];
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertices[2];
}

void CTriangle::Accept(IShapeVisitor & v) const
{
	v.Visit(*this);
}

void CTriangle::AppendProperties(std::ostream & strm) const
{
	strm << "\nVertex1 = " << m_vertices[0].ToString()
		<< "\nVertex2 = " << m_vertices[1].ToString()
		<< "\nVertex3 = " << m_vertices[2].ToString();
}