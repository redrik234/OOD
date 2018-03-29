#pragma once

class CFactory
{
public:
	unique_ptr<IShape> Create(std::vector<std::string> & params);
};