#include "stdafx.h"
#include "CFactory.h"

IShapeCreator & GetShapeCreatorInstance(const std::string & name)
{
	if (name == "TRIANGLE")
	{
		return CTriangleCreator::GetInstance();
	}
	if (name == "RECTANGLE")
	{
		return CRectangleCreator::GetInstance();
	}
	if (name == "CIRCLE")
	{
		return CCircleCreator::GetInstance();
	}
	throw std::invalid_argument("unknown type");
}

unique_ptr<IShape> CFactory::Create(std::vector<std::string> & params)
{
	auto & creator = GetShapeCreatorInstance(params[0]);
	creator.SetParams(params);
	return creator.Create();
}
