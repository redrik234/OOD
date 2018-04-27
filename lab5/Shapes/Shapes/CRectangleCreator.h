#pragma once
#include "IShape.h"
#include "CPoint.h"
#include "IShapeCreator.h"

static const int RECT_PARAM_COUNT = 7;

class CRectangleCreator : public IShapeCreator
{
public:
	static CRectangleCreator & GetInstance();

	std::unique_ptr<IShape> Create() const override;

	void SetParams(std::vector<std::string> & params) override;

	CRectangleCreator(const CRectangleCreator &) = delete;
	CRectangleCreator & operator=(const CRectangleCreator &) = delete;
private:
	CRectangleCreator()
	{
	}

	CPoint m_leftTopPoint;
	CPoint m_rightButtomPoint;
	std::string m_type;
};