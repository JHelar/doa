#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;
/** 
Class Bitstr, does the string conversion between an integer decimal number to a binary string representation.
*/
class Bitstr
{
private:
	string sumstr;
	string binaryStr;

public:

	Bitstr(void)
	{
	}

	~Bitstr(void)
	{
	}

	string getSumstr(){return this->sumstr;}
	string getBinaryStr(){return this->binaryStr;}

	void addstr(string astr, string bstr)
	{
		this->sumstr = astr + bstr;
	}

	void twokomp(int number)
	{
		do
		{
			if ( (number & 1) == 0 )
				binaryStr += "0";
			else
				binaryStr += "1";

			number >>= 1;
		} while ( number );

		reverse(binaryStr.begin(), binaryStr.end());
	}
};

