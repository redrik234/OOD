#pragma once
#include "CShape.h"
#include "CPoint.h"

class CRectangle final: public CShape
{
public:
	CRectangle(const std::string &type, CPoint leftTopPoint, CPoint rightButtomPoint);

	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	CLongNumber GetWidth() const;
	CLongNumber GetHeight() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_leftTop;
	CPoint m_rightButtom;
	CLongNumber m_width;
	CLongNumber m_height;
};