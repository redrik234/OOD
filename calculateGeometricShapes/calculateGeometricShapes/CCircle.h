#pragma once
#include "CShape.h"
#include "CPoint.h"

using namespace std;

class CCircle final : public CShape
{
public:
	CCircle(const string &type, CPoint center, double radius);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetCenter() const;
	double GetRadius() const;
protected:
	void AppendProperties(ostream & strm) const override;
private:
	CPoint m_center;
	double m_radius;
};