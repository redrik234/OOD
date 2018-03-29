#pragma once

static const int RECT_PARAM_COUNT = 7;

class CRectangleCreator : public virtual IShapeCreator
{
public:
	static CRectangleCreator & GetInstance();

	unique_ptr<IShape> Create() const override;

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