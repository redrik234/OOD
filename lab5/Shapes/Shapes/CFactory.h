#pragma once
#include "IShape.h"

class CFactory
{
public:
	std::unique_ptr<IShape> Create(std::vector<std::string> & params);
};