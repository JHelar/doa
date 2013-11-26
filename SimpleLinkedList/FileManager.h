#pragma once

#include <iostream>
#include <fstream>

#include "List.h"

using namespace std;
/** 
Class FileManager, simple class that reads data from file and put the data into the corresponding linked lists.

*/
class FileManager
{
public:
	List<int> Even;
	List<int> unEven;
	List<int> numbers;

	void ReadFile(string fileName)
	{
		ifstream myFile;

		string dummy;
		int dummyI;

		myFile.open(fileName);

		while(!myFile.eof())
		{
			getline(myFile,dummy,'\n');

			dummyI = atoi(dummy.c_str());

			if(dummyI % 2 == 0)
				Even.AddUnique(dummyI);
			else
				unEven.AddUnique(dummyI);
		}
		myFile.close();
	}

	void readAllFromFile(string fileName)
	{
		ifstream myFile;

		string dummy;
		int dummyI;

		myFile.open(fileName);

		while(!myFile.eof())
		{
			getline(myFile,dummy,'\n');

			dummyI = atoi(dummy.c_str());
			numbers.AddUnique(dummyI);
		}

		myFile.close();
	}
};

