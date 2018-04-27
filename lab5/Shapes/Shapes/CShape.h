#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape() = default;
	CShape(const std::string & type);

	std::string GetType() const override;

	std::string ToString() const override;
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	std::string m_type;
};