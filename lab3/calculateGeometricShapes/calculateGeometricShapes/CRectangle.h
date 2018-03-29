#pragma once
#include "CShape.h"
#include "CPoint.h"

class CRectangle final: public CShape
{
public:
	CRectangle(const std::string &type, CPoint leftTopPoint, CPoint rightButtomPoint);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_leftTop;
	CPoint m_rightButtom;
	double m_width;
	double m_height;
};