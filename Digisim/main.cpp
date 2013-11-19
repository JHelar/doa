#include <iostream>
#include <string>

#include "Omvandla.h"
#include "Bitstr.h"
#include "Bit.h"

int main()
{
	Omvandla omv;
	Bitstr bitstr;
	Bit bit;

	string aS;
	string bS;
	
	int go = 1;
	int a = 0;
	int b = 0;

	while(go != 1)
	{
		cout << "Enter a number: ";
		cin >> a;
		cout << "Binary conversion => " << omv.tal_str(a);
		cout << "\nEnter another number: ";
		cin >> b;
		cout << "Binary conversion => " << omv.tal_str(b);
		cout << "\nMultiplication of given binary numbers => " << 
		
	}
	cin.get();
	return 0;
}