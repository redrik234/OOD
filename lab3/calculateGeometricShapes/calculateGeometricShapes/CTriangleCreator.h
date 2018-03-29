#pragma once
static const int TRIANGLE_PARAM_COUNT = 10;

class CTriangleCreator : public virtual IShapeCreator
{
public:
	static CTriangleCreator & GetInstance();

	unique_ptr<IShape> Create() const override;

	void SetParams(std::vector<std::string> & params) override;

	CTriangleCreator(const CTriangleCreator &) = delete;
	CTriangleCreator & operator=(const CTriangleCreator &) = delete;
private:
	CTriangleCreator()
	{
	}

	CPoint m_vertex1; 
	CPoint m_vertex2;
	CPoint m_vertex3;
	std::string m_type;
};