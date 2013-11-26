#include <iostream>

#include "FileManager.h"
#include "Dejt.h"

using namespace std;
/*! \mainpage Dejt
 *
 * \section intro_sec Introduction
 *
 * Dejt reads persons from a list, puts the into two different linked lists based on their gender.
 * Prints out the lists and then pompts the user to input a number that will be the amount of common interests that a couple should have.
 * The program then finds a mathing couple from each list that have the same amount or less amounts of interests.
 * Then it prints out the couples, sorted by the female name.
 *
 */
int main(void)
{
	Dejt dejt;
	FileManager FM;

	int amount = 0;
	
	FM.ReadFile("People.txt");
	cout<<"The female list: \n\n";
	cout<<FM.girlList.str();
	cout<<"\nThe male list: \n\n";
	cout<<FM.boyList.str();
	cout<<"Enter the amount of mathing interests: ";
	cin>>amount;

	dejt.setCouples(FM.boyList,FM.girlList,amount);
	cout<<dejt.PrintCouples();

	cin.get();
	cin.get();
	return 0;
}