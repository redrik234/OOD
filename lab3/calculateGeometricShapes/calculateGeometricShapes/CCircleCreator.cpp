#include "stdafx.h"
#include "CCircleCreator.h"
#include "IShapeCreator.h"

CCircleCreator & CCircleCreator::GetInstance()
{
	static CCircleCreator Instance;
	return Instance;
}

unique_ptr<IShape> CCircleCreator::Create() const
{
	return make_unique<CCircle>(m_type, m_center, m_radius);
}

void CCircleCreator::SetParams(std::vector<std::string> & params)
{
	if (params.size() != CIRCLE_PARAM_COUNT)
	{
		throw std::invalid_argument("Invalid parameter count");
	}
	m_type = params[0];
	m_center = CPoint(stoi(params[2]), stoi(params[3]));
	m_radius = stod(params[5]);
}
