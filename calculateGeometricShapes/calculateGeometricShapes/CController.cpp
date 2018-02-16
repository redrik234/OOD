#include "stdafx.h"
#include "CController.h"
#include "IShape.h"


void CController::Init(std::multimap<std::string, std::vector<std::string>> shapes) 
{
	for (auto it = shapes.begin(); it != shapes.end(); it++)
	{
		if ((*it).first == "CIRCLE")
		{
			m_shapesList.push_back(make_shared<CCircle>(CCircle((*it).first, CPoint(stoi((*it).second[1]), stoi((*it).second[2])),
				stoi((*it).second[4]))));
		}
		if ((*it).first == "RECTANGLE")
		{
			m_shapesList.push_back(make_shared<CRectangle>(CRectangle((*it).first, CPoint(stoi((*it).second[1]), stoi((*it).second[2])),
				CPoint(stoi((*it).second[4]), stoi((*it).second[5])))));
		}
		if ((*it).first == "TRIANGLE")
		{
			m_shapesList.push_back(make_shared<CTriangle>(CTriangle((*it).first, CPoint(stoi((*it).second[1]), stoi((*it).second[2])),
				CPoint(stoi((*it).second[4]), stoi((*it).second[5])),
				CPoint(stoi((*it).second[7]), stoi((*it).second[8])))));
		}
	}
}
void CController::Output() {
	for (auto it = m_shapesList.begin(); it != m_shapesList.end(); it++) {
		cout << (*it)->ToString() << endl;
	}
}