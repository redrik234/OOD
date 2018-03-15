// long_arithmetic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include "longArithmetic.h"

CLongNumber Calculate(const CLongNumber & lV, const CLongNumber & rV, char action)
{
	switch (action)
	{
		case '+':
			return lV + rV;
		case '-':
			return lV - rV;
		case '*':
			return lV * rV;
		case '/':
			return lV / rV;
		default:
			throw std::invalid_argument("incorrect arguments");
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
			<< " " << rValue << " = "
			<< Calculate(lV, rV, action) << std::endl;
	}

    return 0;
}

