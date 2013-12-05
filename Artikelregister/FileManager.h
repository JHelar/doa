#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Hashtable.h"
#include "HashData.h"
#include "Article.h"

using namespace std;
class FileManager
{
public:

	FileManager(void){}

	~FileManager(void){}

	void ReadArticles(string fileName,Hashtable<string,Article> *HT)
	{
		string primeNumber;
		string bucketSize;

		ifstream myFile;
		Article dummyArticle;
		Article emptyArticle;

		myFile.open(fileName);

		myFile >> primeNumber;
		myFile >> bucketSize;

		(*HT).setHashTable(atoi(primeNumber.c_str()),atoi(bucketSize.c_str()),"",emptyArticle);

		while(!myFile.eof())
		{
			myFile >> dummyArticle;
			if(dummyArticle != emptyArticle)
			{
				(*HT).add(Data<string,Article>(dummyArticle.getName(),dummyArticle));
				dummyArticle = emptyArticle;
			}
			else if(dummyArticle == emptyArticle)
				break;
		}
		myFile.close();
	}

	void SaveArticles(string fileName,Hashtable<string,Article> *HT)
	{
		ofstream myFile;
		myFile.open(fileName);
		myFile << (*HT).getPrimeNumber();
		myFile << "\n";
		myFile << (*HT).getBucketSize();
		(*HT).saveHash(myFile);
		myFile.close();
	}
};

