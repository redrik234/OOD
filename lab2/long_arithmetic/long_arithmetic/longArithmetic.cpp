#include "stdafx.h"
#include "longArithmetic.h"
#include <stdexcept>


CLongNumber::CLongNumber(std::string & number)
{
	try
	{
		for (int i = number.size() - 1; i >= 0; --i)
		{
			int num = atoi(number.substr(i, 1).c_str());
			if (num == 0 && number[i] != '0')
			{
				throw std::invalid_argument("invalid number");
			}
			m_number.push_back(num);
		}
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl;
		exit(1);
	}
	Normalize();
}

CLongNumber::CLongNumber(int number)
{
	while (number != 0)
	{
		m_number.push_back(number % 10);
		number /= 10;
	}
}

int CLongNumber::GetSize() const
{
	return m_number.size();
}

const CLongNumber & CLongNumber::operator=(const CLongNumber & number)
{
	if (&number != this)
	{
		m_number = number.m_number;
	}

	return *this;
}

void CLongNumber::Normalize()
{
	while (m_number.size() > 1 && m_number.back() == 0)
		m_number.pop_back();
}

const CLongNumber operator+(const CLongNumber & lValue, const CLongNumber & rValue)
{
	CLongNumber result = lValue;
	CLongNumber operand = rValue;

	int carry = 0;
	for (int i = 0; i < result.GetSize() || carry; ++i) 
	{
		if (operand.GetSize() < result.GetSize() && i == operand.GetSize())
		{
			operand.m_number.push_back(0);
		}
		if (i == result.GetSize())
		{
			result.m_number.push_back(0);
		}
		result.m_number[i] += carry + (i < operand.GetSize() ? operand.m_number[i] : 0);

		carry = result.m_number[i] >= 10;
		if (carry)
		{
			result.m_number[i] -= 10;
		}
	}
	result.Normalize();
	return result;
}

const CLongNumber operator-(const CLongNumber & lValue, const CLongNumber & rValue)
{
	CLongNumber result = lValue;
	CLongNumber operand = rValue;
	int carry = 0;
	for (int i = 0; i < operand.GetSize() || carry != 0; ++i)
	{
		result.m_number[i] -= carry + (i < operand.GetSize() ? operand.m_number[i] : 0);
		carry = result.m_number[i] < 0;
		if (carry)
		{
			result.m_number[i] += 10;
		}
	}
	result.Normalize();
	return result;
}

const CLongNumber operator*(const CLongNumber & lValue, const CLongNumber & rValue)
{
	CLongNumber result;
	
	int length = lValue.GetSize() + rValue.GetSize();
	result.m_number.resize(length);

	for (int ix = 0; ix < rValue.GetSize(); ++ix)
		for (int jx = 0; jx < lValue.GetSize(); ++jx)
			result.m_number[ix + jx] += rValue.m_number[ix] * lValue.m_number[jx];

	for (int ix = 0; ix < length; ix++)
	{
		if (ix + 1 != length)
		{
			result.m_number[ix + 1] += result.m_number[ix] / 10;
		}
		else
		{
			result.m_number.push_back(result.m_number[ix] / 10);
		}
		result.m_number[ix] %= 10;
	}

	while (result.m_number[length] == 0)
		length--;
	result.Normalize();
	return result;
}

const CLongNumber operator/(const CLongNumber & lValue, const CLongNumber & rValue)
{
	CLongNumber dividend;
	CLongNumber result;
	CLongNumber quotient;

	for (int i = lValue.GetSize() - 1; i >= 0; --i)
	{
		if(!(dividend > rValue))
		{
			if (dividend.GetSize() == 1 && dividend.m_number[0] == 0) 
			{
				dividend.m_number.pop_back();
			}
			std::reverse(std::begin(dividend.m_number), std::end(dividend.m_number));
			dividend.m_number.push_back(lValue.m_number[i]);
			std::reverse(std::begin(dividend.m_number), std::end(dividend.m_number));
		}

		if(dividend >= rValue)
		{
			CLongNumber divider = rValue;
			int j = 1;
			if (dividend == divider)
			{
				++j;
			}
			else
			{
				while (dividend >= divider)
				{
					++j;
					divider = rValue * CLongNumber(j);
				}
			}
			result.m_number.push_back(j - 1);
			dividend = dividend - rValue * CLongNumber(j - 1);
		}
		else
		{
			if (result.GetSize() != 0)
			{
				result.m_number.push_back(0);
			}
		}
	}
	std::reverse(std::begin(result.m_number), std::end(result.m_number));
	result.Normalize();
	return result;
}

const bool operator>(const CLongNumber & lValue, const CLongNumber & rValue)
{
	if (lValue.GetSize() > rValue.GetSize())
	{
		return true;
	}
	else if (lValue.GetSize() == rValue.GetSize())
	{
		for (int i = lValue.GetSize() - 1; i >= 0; --i)
		{
			if (lValue.m_number[i] > rValue.m_number[i])
			{
				return true;
			}
			else if (lValue.m_number[i] < rValue.m_number[i])
			{
				return false;
			}
		}
	}
	
	return false;
}

const bool operator>=(const CLongNumber & lValue, const CLongNumber & rValue)
{
	if (lValue.GetSize() > rValue.GetSize())
	{
		return true;
	}
	else if (lValue.GetSize() == rValue.GetSize())
	{
		for (int i = lValue.GetSize() - 1; i >= 0; --i)
		{
			if (lValue.m_number[i] < rValue.m_number[i])
			{
				return false;
			}
			else if (lValue.m_number[i] > rValue.m_number[i]) {
				return true;
			}
		}
		return true;
	}

	return false;
}

const bool operator==(const CLongNumber & lValue, const CLongNumber & rValue)
{
	if (lValue.GetSize() == rValue.GetSize())
	{
		for (int i = lValue.GetSize() - 1; i >= 0; --i)
		{
			if (lValue.m_number[i] != rValue.m_number[i])
			{
				return false;
			}
		}
		return true;
	}

	return false;
}

std::ostream & operator<<(std::ostream & output, const CLongNumber & number)
{
	for (int i = number.GetSize() - 1; i >= 0; --i)
	{
		output << number.m_number[i];
	}
	return output;
}