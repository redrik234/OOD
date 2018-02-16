#pragma once
#include "CShape.h"
#include "CPoint.h"

class CLineSegment final: public CShape
{
public:
	CLineSegment() = default;

	CLineSegment(CPoint startPoint, CPoint endPoint);

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const override;
	double GetPerimeter() const override;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};