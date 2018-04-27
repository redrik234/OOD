#pragma once
#include "IShapeVisitor.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "IShape.h"

class CStreamOutputVisitor : public IShapeVisitor
{
public:
	void Visit(const CCircle & circle) override;
	void Visit(const CRectangle & rectangle) override;
	void Visit(const CTriangle & triangle) override;
	void Print(std::ostream & out, const IShape & shape);
private:
	std::ostringstream strm;
};