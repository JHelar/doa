#pragma once

#include <iostream>

using namespace std;
/** 
Class bit, have all logic gate functions and the add function of two binary strings.
*/
class Bit
{
public:

	Bit(void)
	{
	}

	~Bit(void)
	{
	}

	char and(char a, char b)
	{
		if(a == '1')
			if(b == '1')
				return '1';
		else 
			return '0';
	}

	char or(char a, char b)
	{
		if(a != b)
			return '1';
		else if(a == '1')
			if(b == '1')
				return '1';
		else
			return '0';
	}

	char xor(char a, char b)
	{
		if(a != b)
			return '1';
		else
			return '0';
	}

	char not(char a)
	{
		if(a == '1')
			return '0';
		else
			return '1';
	}

	char nand(char a, char b)
	{
		if(a == '1')
			if(b == '1')
				return '0';
		else
			return '1';
	}

	char nor(char a, char b)
	{
		if(a == '0')
			if(b == '0')
				 return '1';
		else 
			return '0';
	}

	string add(string a, string b)
	{
		string sum;
		char ci = '0';

		if (a.size() > b.size())
		{
			for (int i = b.size(); i < a.size(); i++)
			{
				b.insert(0,"0");
			}
		}
		else if (a.size() < b.size())
		{
			for (int i = a.size(); i < b.size(); i++)
			{
				a.insert(0,"0");
			}
		}

		for(int i = a.size() -1; i >= 0; i--)
		{
			sum += xor(xor(a[i],b[i]),ci);
			ci = or(and(or(a[i],b[i]),ci),and(a[i],b[i]));
		}

		sum += ci;
		sum = string(sum.rbegin(), sum.rend());
		
		return sum;
	}
	
};

