#include "stdafx.h"
#include "CShape.h"

CShape::CShape(const std::string & type)
	: m_type(type)
{
}

std::string CShape::GetType() const
{
	return m_type;
}

std::string CShape::ToString() const
{
	std::ostringstream strm;
	strm << "==========================\n" << m_type << ":"
		<< "\n\nArea = " << GetArea()
		<< "\nPerimeter = " << GetPerimeter() << "\n";
	AppendProperties(strm);
	strm << "\n==========================\n";
	return strm.str();
}