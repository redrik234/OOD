#pragma once
#include "CShape.h"
#include "CPoint.h"
#include "longArithmetic.h"
#include "IShapeCreator.h"

static const int PI = 314;

class CCircle final : public CShape
{
public:
	CCircle(const std::string &type, CPoint center, const CLongNumber & radius);
	~CCircle() = default;

	CLongNumber GetArea() const override;
	CLongNumber GetPerimeter() const override;

	CPoint GetCenter() const;
	CLongNumber GetRadius() const;

	void Accept(IShapeVisitor & v) const override;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_center;
	CLongNumber m_radius;
};