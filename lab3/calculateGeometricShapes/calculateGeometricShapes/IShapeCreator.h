#pragma once
#include "stdafx.h"

class IShapeCreator
{
public:
	virtual ~IShapeCreator() = default;
	virtual unique_ptr<IShape> Create() const = 0;
	virtual void SetParams(std::vector<string> & params) = 0;
};