#pragma once
#include "CShape.h"
#include "CPoint.h"
#include "CLineSegment.h"

class CTriangle final: public CShape
{
public:
	CTriangle(const string &type, CPoint vertex1, CPoint vertex2, CPoint vertex3);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	vector<CPoint> m_vertices;
};