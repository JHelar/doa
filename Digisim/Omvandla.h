#pragma once

#include <iostream>
#include <string>

#include "Bitstr.h"

using namespace std;
/** 
Class Omvandla, converts decimal to binary string and binary string to a decimal version of it.
*/
class Omvandla
{
public:

	Omvandla(void)
	{
	}

	~Omvandla(void)
	{
	}

	string tal_str(int tal)
	{
		Bitstr bitStr;
		int n = 0;

		bitStr.twokomp(tal);
		return bitStr.getBinaryStr();
	}

	int str_tal(string str)
	{
		int Rslt = 0;
		int Mask = 1;
		for (int i = str.length()-1; i >= 0; --i, Mask <<= 1) {
			if (str.at(i) != '0')
			{
				Rslt |= Mask;
			}
		}
		return Rslt;
	}
};

