#pragma once
#include "IShape.h"
#include "CPoint.h"
#include "IShapeCreator.h"

static const int CIRCLE_PARAM_COUNT = 6;

class CCircleCreator : public IShapeCreator
{
public:
	static CCircleCreator & GetInstance();

	std::unique_ptr<IShape> Create() const override;

	void SetParams(std::vector<std::string> & params) override;

	CCircleCreator(const CCircleCreator &) = delete;
	CCircleCreator & operator=(const CCircleCreator &) = delete;
private:
	CCircleCreator()
	{
	}

	CPoint m_center;
	CLongNumber m_radius;
	std::string m_type;
};