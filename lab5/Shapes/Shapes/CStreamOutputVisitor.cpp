#include "stdafx.h"
#include "CStreamOutputVisitor.h"

void CStreamOutputVisitor::Visit(const CCircle & circle)
{
	strm << "==========================\n" << circle.GetType() << ":"
		<< "\n\nArea = " << circle.GetArea()
		<< "\nPerimeter = " << circle.GetPerimeter() << "\n";
	strm << "\n==========================\n";
}

void CStreamOutputVisitor::Visit(const CRectangle & rectangle)
{
	strm << "==========================\n" << rectangle.GetType() << ":"
		<< "\n\nArea = " << rectangle.GetArea()
		<< "\nPerimeter = " << rectangle.GetPerimeter() << "\n";
	strm << "\n==========================\n";
}

void CStreamOutputVisitor::Visit(const CTriangle & triangle)
{
	strm << "==========================\n" << triangle.GetType() << ":"
		<< "\n\nArea = " << triangle.GetArea()
		<< "\nPerimeter = " << triangle.GetPerimeter() << "\n";
	strm << "\n==========================\n";
}

void CStreamOutputVisitor::Print(std::ostream & out, const IShape & shape)
{
	shape.Accept(*this);
	out << strm.str();
}
