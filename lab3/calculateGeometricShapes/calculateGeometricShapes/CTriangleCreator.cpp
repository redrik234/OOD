#include "stdafx.h"
#include "CTriangleCreator.h"
#include "IShapeCreator.h"

CTriangleCreator & CTriangleCreator::GetInstance()
{
	static CTriangleCreator Instance;
	return Instance;
}

unique_ptr<IShape> CTriangleCreator::Create() const
{
	return make_unique<CTriangle>(m_type, m_vertex1, m_vertex2, m_vertex3);
}

void CTriangleCreator::SetParams(std::vector<std::string> & params)
{
	if (params.size() != TRIANGLE_PARAM_COUNT)
	{
		throw std::invalid_argument("Invalid parameter count");
	}
	m_type = params[0];
	m_vertex1 = CPoint(stoi(params[2]), stoi(params[3]));
	m_vertex2 = CPoint(stoi(params[5]), stoi(params[6]));
	m_vertex3 = CPoint(stoi(params[8]), stoi(params[9]));
}