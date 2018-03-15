#pragma once

class CLongNumber final
{
public:
	CLongNumber() = default;
	CLongNumber(std::string & number);
	CLongNumber(int number);

	int GetSize() const;
	void Normalize();

	const CLongNumber& operator=(const CLongNumber & number);

	friend const CLongNumber operator+(const CLongNumber & lValue, const CLongNumber & rValue);
	friend const CLongNumber operator-(const CLongNumber & lValue, const CLongNumber & rValue);
	friend const CLongNumber operator*(const CLongNumber & lValue, const CLongNumber & rValue);
	friend const CLongNumber operator/(const CLongNumber & lValue, const CLongNumber & rValue);
	
	friend const bool operator>(const CLongNumber & lValue, const CLongNumber & rValue);
	friend const bool operator>=(const CLongNumber & lValue, const CLongNumber & rValue);
	friend const bool operator==(const CLongNumber & lValue, const CLongNumber & rValue);

	friend std::ostream & operator<<(std::ostream & output, const CLongNumber & number);

private:
	std::vector<int> m_number;
};