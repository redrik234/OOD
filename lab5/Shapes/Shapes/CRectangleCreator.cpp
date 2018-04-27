#include "stdafx.h"
#include "CRectangleCreator.h"
#include "CPoint.h"
#include "longArithmetic.h"
#include "CRectangle.h"
#include "IShape.h"
#include "IShapeCreator.h"

CRectangleCreator & CRectangleCreator::GetInstance()
{
	static CRectangleCreator Instance;
	return Instance;
}

std::unique_ptr<IShape> CRectangleCreator::Create() const
{
	return std::make_unique<CRectangle>(m_type, m_leftTopPoint, m_rightButtomPoint);
}

void CRectangleCreator::SetParams(std::vector<std::string> & params)
{
	if (params.size() != RECT_PARAM_COUNT)
	{
		throw std::invalid_argument("Invalid parameter count");
	}
	m_type = params[0];
	m_leftTopPoint = CPoint(params[2], params[3]);
	m_rightButtomPoint = CPoint(params[5], params[6]);
}