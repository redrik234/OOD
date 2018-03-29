#include "stdafx.h"
#include "CRectangleCreator.h"
#include "IShapeCreator.h"

CRectangleCreator & CRectangleCreator::GetInstance()
{
	static CRectangleCreator Instance;
	return Instance;
}

unique_ptr<IShape> CRectangleCreator::Create() const
{
	return make_unique<CRectangle>(m_type, m_leftTopPoint, m_rightButtomPoint);
}

void CRectangleCreator::SetParams(std::vector<std::string> & params)
{
	if (params.size() != RECT_PARAM_COUNT)
	{
		throw std::invalid_argument("Invalid parameter count");
	}
	m_type = params[0];
	m_leftTopPoint = CPoint(stoi(params[2]), stoi(params[3]));
	m_rightButtomPoint = CPoint(stoi(params[5]), stoi(params[6]));
}