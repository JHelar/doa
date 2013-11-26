#include <iostream>

#include "FileManager.h"
#include "Watch.h"

/* Q: Hur mycket snabbare kan man räkna med att versionen med två listor blir?                 
   A: Ca: halva tiden vid stor mängd tal då listornas search-funktion bara i värsta fall behöver söka igenom n/2 om det är lika många jämna som udda tal i filen.                  
   
   Q: Vad är tidskomplexiteterna för de två versionerna? Motivera svaret.                 
   A: O(n) för båda då det enbart är en loop som körs, den i Search-funktionen                  
   
   Q: Mät tiden, hur mycket snabbare blev det?                
   A: Ca:10% snabbare. Beror nog på att inläsningen från fil kommer att ta lika lång tid.         
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