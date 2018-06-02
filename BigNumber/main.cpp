

#include "stdafx.h"

#include "BigNumber.h"

int main()
{
	// Creates two objects of BigNumber
	BigNumber a("1234567891");
	BigNumber b("1234567812");

	// All the answers to the different functions
	BigNumber addAnswer, subtractAnswer, multAnswer, divideAnswer, modAnswer;
 
	addAnswer = a + b;
	subtractAnswer = a - b;
	multAnswer = a * b;
	divideAnswer = a / b;
	modAnswer = a % b;
     
	//Printing out the values
	cout << "a = "; // value of a
	a.print();
	cout << "b = "; // value of b
	b.print();

	cout << "a + b = "; // addition output
	addAnswer.print();

	cout << "a - b = ";      //  subtraction output
	subtractAnswer.print();

	cout << "a * b = ";   // multiplication output
	multAnswer.print();

	cout << "a / b = ";    // division ouptut 
	divideAnswer.print();

	cout << "a % b = "; // modulus output 
	modAnswer.print();
}
