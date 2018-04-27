#pragma once

class CCircle;
class CTriangle;
class CRectangle;

class IShapeVisitor
{
public:
	virtual void Visit(const CCircle & circle) = 0;
	virtual void Visit(const CRectangle & rectangle) = 0;
	virtual void Visit(const CTriangle & triangle) = 0;
	virtual ~IShapeVisitor() = default;
};