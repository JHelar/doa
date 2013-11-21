#include <iostream>
#include <string>

#include "Omvandla.h"
#include "Bitstr.h"
#include "Bit.h"

/*! \mainpage Digisim
 *
 * \section intro_sec Introduction
 *
 * Digisim converts given decimal numbers to it's binary representation and then bit add them together and displays the result in both binary and decimal. 
 *
 */


int main()
{
	Omvandla omv;
	Bitstr bitstr;
	Bit bit;

	string aS;
	string bS;
	string sum;
	
	int a = 1;
	int b = 1;

	char ci = '0';

	while( a != 0 || b != 0)
	{
		cout << "\nEnter a number: ";
		cin >> a;
		aS = omv.tal_str(a);
		cout << "Binary conversion => " << aS;
		cout << "\nEnter another number: ";
		cin >> b;
		bS = omv.tal_str(b);
		cout << "Binary conversion => " << bS;
		sum = bit.add(aS,bS);
		cout << "\nMultiplication of given binary numbers => "<<sum << "\nDecimal version => "<<omv.str_tal(sum);

	}
	cin.get();
	return 0;
}