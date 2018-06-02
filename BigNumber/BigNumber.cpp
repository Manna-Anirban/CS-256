#include "stdafx.h"
#include "BigNumber.h"
#include "math.h"

// First Constructor for BigNumber 
// which accepts a string value
BigNumber::BigNumber(string s)
{
	for (int i = 0; i<s.size(); i++) {
		if (s[i] != '-')
		{
			number.push_back(s[i] - '0');

		}
	}

}

// Default constructor for BigNumber
BigNumber::BigNumber()
{
	number.push_back(0);
}

//Operator overloading for add method
BigNumber BigNumber::operator +(const BigNumber & x)
{
	BigNumber answer;
	answer.number.clear();
	add(number, x.number, answer.number);

	return answer;
}
//Operator overloading for the subtract method
BigNumber BigNumber::operator -(const BigNumber & x)
{

	BigNumber answer;
	answer.number.clear();
	subtract(number, x.number, answer.number);

	return answer;
}

//Operator overlaoding for the multiply method
BigNumber BigNumber::operator *(const BigNumber & x)
{
	BigNumber answer;
	answer.number.clear();
	multiply(number, x.number, answer.number);
	return answer;

}

// Operator overloading for the divide method
BigNumber BigNumber::operator /(const BigNumber & x)
{
	BigNumber answer;
	answer.number.clear();
	divide(number, x.number, answer.number);
	return answer;
}

// Operator overloading for the modulus method
BigNumber BigNumber::operator %(const BigNumber & x)
{
	BigNumber answer;
	answer.number.clear();
	modulus(number, x.number, answer.number);
	return answer;
}

// Defines the add function by adding two vectors values together
void BigNumber::add(const vector <int> & x, const vector <int> & y, vector <int> & z)
{
	long long int firstNum = 0;
	long long int secondNum = 0;
	long long int sum = 0;
	BigNumber answer;
	answer.number.clear();
	int multFactor = 1;
	for (int i = x.size() - 1; i >= 0; i--)
	{
		firstNum += x[i] * multFactor;
		multFactor *= 10;
	}
	multFactor = 1;
	for (int i = y.size() - 1; i >= 0; i--)
	{
		secondNum += y[i] * multFactor;
		multFactor *= 10;
	}
	sum = firstNum + secondNum;
	while (sum>0)
	{
		z.push_back(sum % 10);
		sum = sum / 10;
	}
	Flip(z);

}
// // Defines the subtract function by taking the difference of two vectors
void BigNumber::subtract(const vector <int> & x, const vector <int> & y, vector <int> & z)
{
	long long int firstNum = 0;
	long long int secondNum = 0;
	long long int difference = 0;
	BigNumber answer;
	answer.number.clear();
	int multFactor = 1;

	for (int i = x.size() - 1; i >= 0; i--)
	{
		firstNum += x[i] * multFactor;
		multFactor *= 10;
	}
	multFactor = 1;
	for (int i = y.size() - 1; i >= 0; i--)
	{
		secondNum += y[i] * multFactor;
		multFactor *= 10;
	}
	difference = firstNum - secondNum;
	while (difference > 0)
	{
		z.push_back(difference % 10);
		difference /= 10;
	}
	Flip(z);

}
// Defining the multiply method by multiplying the vector values
void BigNumber::multiply(const vector <int> & x, const vector <int> & y, vector <int> & z)
{
	long long int firstNum = 0;
	long long int secondNum = 0;
	long long int product = 1;
	BigNumber answer;
	answer.number.clear();
	int multFactor = 1;

	for (int i = x.size() - 1; i >= 0; i--)
	{
		firstNum += x[i] * multFactor;
		multFactor *= 10;
	}
	multFactor = 1;
	for (int i = y.size() - 1; i >= 0; i--)
	{
		secondNum += y[i] * multFactor;
		multFactor *= 10;
	}
	product = firstNum * secondNum;
	while (product > 0)
	{
		z.push_back(product % 10);
		product /= 10;
	}
	Flip(z);

}
// Dividing the two vectors, which will output an int 
void BigNumber::divide(const vector <int> & x, const vector <int> & y, vector <int> & z)
{
	long long int firstNum = 0;
	long long int secondNum = 1;
	long long int quotient = 1;
	BigNumber answer;
	answer.number.clear();
	int multFactor = 1;

	for (int i = x.size() - 1; i >= 0; i--)
	{
		firstNum += x[i] * multFactor;
		multFactor *= 10;
	}
	multFactor = 1;
	for (int i = y.size() - 1; i >= 0; i--)
	{
		secondNum += y[i] * multFactor;
		multFactor *= 10;
	}
	quotient = firstNum / secondNum;
	while (quotient > 0)
	{
		z.push_back(quotient % 10);
		quotient /= 10;
	}
	Flip(z);

}
// Finding the remainder of the two vectors
void BigNumber::modulus(const vector <int> & x, const vector <int> & y, vector <int> & z)
{
	long long int firstNum = 0;
	long long int secondNum = 1;
	long long int remainder = 1;
	BigNumber answer;
	answer.number.clear();
	int multFactor = 1;
	for (int i = x.size() - 1; i >= 0; i--)
	{
		firstNum += x[i] * multFactor;
		multFactor *= 10;
	}
	multFactor = 1;
	for (int i = y.size() - 1; i >= 0; i--)
	{
		secondNum += y[i] * multFactor;
		multFactor *= 10;
	}
	remainder = firstNum % secondNum;
	while (remainder>0)
	{
		z.push_back(remainder % 10);
		remainder = remainder / 10;
	}
	Flip(z);

}

// necessary to read back the value of the answer;
// Otherwise the value is backwards
void BigNumber::Flip(vector <int> & bigNum)
{
	int swap;
	int vectorValue = bigNum.size() - 1;
	for (int i = 0; i< bigNum.size() / 2; i++)
	{
		swap = bigNum[i];
		bigNum[i] = bigNum[vectorValue];
		bigNum[vectorValue] = swap;
		vectorValue -= 1;
	}
}
// Properly formats and prints the result
void BigNumber::print()
{
	bool zeroDigit = false;
	for (int i = 0; i < number.size(); i++)
	{
		if (number.size() != 1 && number[i] == 0 && zeroDigit == false)
		{
			number[i] = number[i];
		}
		else
		{
			zeroDigit = true;
			cout << number[i];
		}
	}
	cout << endl;
}
