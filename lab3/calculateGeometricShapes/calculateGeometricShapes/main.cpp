// calculateGeometricShapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "IShape.h"
#include "CFactory.h"
#include "IShapeCreator.h"

using namespace std;


int main(int argc, char* argv[])
{
	ifstream fileWithShapes(argv[1]);
	ofstream output("output.txt");
	string line;

	char strWithArguments[255];
	char seps[] = ";:,= ";
	char *tokens;
	char *nextToken = NULL;

	CFactory factory;

	while (fileWithShapes.getline(strWithArguments, 255)) 
	{
		tokens = strtok_s(strWithArguments, seps, &nextToken);
		vector<string> params;
		params.push_back(tokens);

		while (tokens != NULL) 
		{
			tokens = strtok_s(NULL, seps, &nextToken);
			if (tokens != NULL) {
				params.push_back(tokens);
			}
		}

		try 
		{
			unique_ptr<IShape> shape = factory.Create(params);
			output << shape->ToString();
		}
		catch (std::exception & ex)
		{
			cout << ex.what() << endl;
		}

	}


    return 0;
}

