#pragma once
class CController
{
public:
	void Init(std::multimap<std::string, std::vector<std::string>> shapes);
	void Output();
private:
	std::multimap<std::string, std::vector<std::string>> m_shapes;
	std::vector<std::shared_ptr<IShape>> m_shapesList;
};