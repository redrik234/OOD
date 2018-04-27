#pragma once
#include "stdafx.h"
#include "IShape.h"

class IShapeCreator
{
public:
	virtual ~IShapeCreator() = default;
	virtual std::unique_ptr<IShape> Create() const = 0;
	virtual void SetParams(std::vector<std::string> & params) = 0;
};