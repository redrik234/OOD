#include "stdafx.h"
#include "CTriangleCreator.h"
#include "IShapeCreator.h"
#include "CTriangle.h"
#include "CPoint.h"
#include "longArithmetic.h"

CTriangleCreator & CTriangleCreator::GetInstance()
{
	static CTriangleCreator Instance;
	return Instance;
}

std::unique_ptr<IShape> CTriangleCreator::Create() const
{
	return std::make_unique<CTriangle>(m_type, m_vertex1, m_vertex2, m_vertex3);
}

void CTriangleCreator::SetParams(std::vector<std::string> & params)
{
	if (params.size() != TRIANGLE_PARAM_COUNT)
	{
		throw std::invalid_argument("Invalid parameter count");
	}
	m_type = params[0];
	m_vertex1 = CPoint(params[2], params[3]);
	m_vertex2 = CPoint(params[5], params[6]);
	m_vertex3 = CPoint(params[8], params[9]);
}