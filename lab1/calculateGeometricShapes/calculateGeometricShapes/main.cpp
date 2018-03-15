// calculateGeometricShapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "IShape.h"
#include "CController.h"

using namespace std;


int main(int argc, char* argv[])
{
	ifstream fileWithShapes(argv[1]);
	string line;

	char strWithArguments[255];
	char seps[] = ";:,= ";
	char *tokens;
	char *nextToken = NULL;

	multimap<string, vector<string>> shapes;

	while (fileWithShapes.getline(strWithArguments, 255)) 
	{
		tokens = strtok_s(strWithArguments, seps, &nextToken);
		
		string typeShape = tokens;
		vector<string> params;

		while (tokens != NULL) 
		{
			tokens = strtok_s(NULL, seps, &nextToken);
			if (tokens != NULL) {
				params.push_back(tokens);
			}
		}
		shapes.insert(pair<string, vector<string>>(typeShape, params));
	}

	CController controller;
	controller.Init(shapes);
	controller.Output();

    return 0;
}

