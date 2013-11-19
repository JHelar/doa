#pragma once

#include <iostream>

using namespace std;
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

	void add(char a, char b, char ci, char sum, char cu)
	{
		sum = xor(xor(a,b),ci);
		cu = or(and(or(a,b),ci),and(a,b));
	}

};

