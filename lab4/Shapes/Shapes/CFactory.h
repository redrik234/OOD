#pragma once

class CFactory
{
public:
	std::unique_ptr<IShape> Create(std::vector<std::string> & params);
};