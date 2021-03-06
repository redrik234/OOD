// long_arithmetic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include "longArithmetic.h"

void Calculate(const CLongNumber & lV, const CLongNumber & rV, char action, std::ofstream & output)
{
	CLongNumber result;
	
	try
	{
		switch (action)
		{
		case '+':
			result = lV + rV;
			break;
		case '-':
			result = lV - rV;
			break;
		case '*':
			result = lV * rV;
			break;
		case '/':
			result = lV / rV;
			break;
		}
		output << result << std::endl;
	}
	catch (const std::invalid_argument & ex)
	{
		//std::cout << ex.what() << std::endl;
		output << ex.what() << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::string lValue;
	std::string rValue;
	char action;

	if (argc != 2)
	{
		std::cout << "Input example: long_arithmetic.exe <filename.txt>" << std::endl;
		exit(1);
	}
	std::ifstream input(argv[1]);
	std::ofstream output("output.txt");

	while (input >> lValue >> action >> rValue)
	{
		CLongNumber lV(lValue);
		CLongNumber rV(rValue);
		output << lValue << " " << action
			<< " " << rValue << " = ";
		Calculate(lV, rV, action, output);
	}

    return 0;
}

