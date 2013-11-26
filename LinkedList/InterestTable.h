#pragma once

#include <iostream>

using namespace std;
/** Class InterestTable, simple class with boolean data that represents the different interests a person can have */
class InterestTable
{
protected:
	bool bio;
	bool dans;
	bool idrott;
	bool resor;
	bool datorspel;
public:

	InterestTable(void)
	{
		bio=dans=idrott=resor=resor=datorspel = false;
	}

	~InterestTable(void)
	{
	}
};

