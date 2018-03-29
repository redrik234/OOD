#include "stdafx.h"
#include "CCircleCreator.h"
#include "IShape.h"
#include "CCircle.h"
#include "IShapeCreator.h"
#include "longArithmetic.h"

CCircleCreator & CCircleCreator::GetInstance()
{
	static CCircleCreator Instance;
	return Instance;
}

std::unique_ptr<IShape> CCircleCreator::Create() const
{
	return std::make_unique<CCircle>(m_type, m_center, m_radius);
}

void CCircleCreator::SetParams(std::vector<std::string> & params)
{
	if (params.size() != CIRCLE_PARAM_COUNT)
	{
		throw std::invalid_argument("Invalid parameter count");
	}
	m_type = params[0];
	m_center = CPoint(params[2], params[3]);
	m_radius = CLongNumber(params[5]);
}
