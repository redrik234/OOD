#pragma once
#include "IShape.h"

class CShape : public virtual IShape
{
public:
	CShape() = default;
	CShape(const std::string & type);

	std::string ToString() const override;
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	std::string m_type;
};