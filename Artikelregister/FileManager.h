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
private:
	Hashtable<string, Article> HT;
public:

	FileManager(void){}

	~FileManager(void){}

	void ReadArticles(string fileName)
	{
		char primeNumber;
		char bucketSize;
		ifstream myFile;
		Article dummyArticle;
		Article emptyArticle;

		myFile >> primeNumber;
		myFile >> bucketSize;

		HT.setHashTable(int(primeNumber),int(bucketSize),"",emptyArticle);

		myFile.open(fileName);
		while(!myFile.eof())
		{
			myFile >> dummyArticle;
			if(dummyArticle != emptyArticle)
			{
				HT.add(Data<string,Article>(dummyArticle.getName(),dummyArticle));
				dummyArticle = emptyArticle;
			}
			else if(dummyArticle == emptyArticle)
				break;
		}
		myFile.close();
	}
};

