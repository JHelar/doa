#include <iostream>

#include "FileManager.h"
#include "Watch.h"

/* Q: Hur mycket snabbare kan man r�kna med att versionen med tv� listor blir?                 
   A: Ca: halva tiden vid stor m�ngd tal d� listornas search-funktion bara i v�rsta fall beh�ver s�ka igenom n/2 om det �r lika m�nga j�mna som udda tal i filen.                  
   
   Q: Vad �r tidskomplexiteterna f�r de tv� versionerna? Motivera svaret.                 
   A: O(n) f�r b�da d� det enbart �r en loop som k�rs, den i Search-funktionen                  
   
   Q: M�t tiden, hur mycket snabbare blev det?                
   A: Ca:10% snabbare. Beror nog p� att inl�sningen fr�n fil kommer att ta lika l�ng tid.         
*/ 
/*! \mainpage Digisim
 *
 * \section intro_sec Introduction
 *
 * Uses a single linked list. Reads integers from file and puts the unique numbers into a single linked list. 
 * Also puts the integers into two lists one for the even and one for the uneven numbers.
 * Prints out the time it took to input the data into the lists.
 * Prints out the even and uneven lists and uses the iterators in the linked list in order to print out all of the numbers.
 *
 */
int main(void)
{
	FileManager FM;
	Course::Watch w;
	w.restart();
	for(int i = 0; i < 10000; i++)
		FM.readAllFromFile("Numbers.txt");
	cout << "It took " << w.elapsedNs().count()/10000 << " ns, to put the data to one linked list\n";
	w.restart();
	for(int i = 0; i < 10000; i++)
		FM.ReadFile("Numbers.txt");
	cout << "It took " << w.elapsedNs().count()/10000 << " ns, to put the data to two linked lists\n";

	cout << "Even numbers from file: \n";
	cout << FM.Even.strWithSpace();
	cout << "\nUneven numbers from file: \n";
	cout << FM.unEven.strWithSpace();

	cout << "\nUsing the iterators for the numbers: \n";

	for (auto iter = FM.numbers.begin(); iter != FM.numbers.end(); iter++)
	{
		cout << (*iter).info << "\n";
	}
	cin.get();
	return 0;
}