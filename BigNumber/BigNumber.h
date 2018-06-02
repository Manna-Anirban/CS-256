#pragma once
#include <iostream>
#include <vector> 
#include <string>

using namespace std;


class BigNumber
{
private:
	// defining the private functions and the vector
	vector <int> number;
	void add(const vector <int> &x, const vector <int> &y, vector <int> &z);
	void subtract(const vector <int> &x, const vector <int> &y, vector <int> &z);
	void multiply(const vector <int> & x, const vector <int> & y, vector <int> & z);
	void divide(const vector <int> & x, const vector <int> & y, vector <int> & z);
	void modulus(const vector <int> & x, const vector <int> & y, vector <int> & z);
	void Flip(vector <int> & r);
public:
	// defining the constructor and the operator methods 
	BigNumber(string s);
	BigNumber();
	BigNumber operator +(const BigNumber & r);
	BigNumber operator -(const BigNumber & r);
	BigNumber operator *(const BigNumber & r);
	BigNumber operator /(const BigNumber & r);
	BigNumber operator %(const BigNumber & r);
	// print method
	void print();
};
