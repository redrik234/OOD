#pragma once
#include "CShape.h"
#include "CPoint.h"
#include "longArithmetic.h"

class CTriangle final: public CShape
{
public:
	CTriangle(const std::string &type, CPoint vertex1, CPoint vertex2, CPoint vertex3);

	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	std::vector<CPoint> m_vertices;
};