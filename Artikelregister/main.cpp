#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Hashtable.h"
#include "HashData.h"
#include "FileManager.h"
#include "Article.h"
#include "ManageHashData.h"

string menu()
{
	ostringstream oss;

	oss << "!MAIN MENU!" << endl;
	oss << "1.Add an article" << endl;
	oss << "2.Edit an article" << endl;
	oss << "3.Remove an article" << endl;
	oss << "4.Print articles" << endl;
	oss << "5.Read articles from file" << endl;
	oss << "6.Save articles to file" << endl;
	oss << "7.Exit" << endl;
	oss << "Choice: ";
	return oss.str();
}

int main(void)
{
	Hashtable<string,Article> *HT = new Hashtable<string,Article>;
	Data<string,Article> data;
	FileManager FM;
	ManageHashData MHD;
	

	string choice;
	int choiceINT;
	
	bool go = true;

	while(go)
	{
		system("cls");
		cout << menu();
		getline(cin,choice,'\n');
		choiceINT = atoi(choice.c_str());

		switch(choiceINT)
		{
		case 1:
			system("cls");
			MHD.addData(HT);
			cout << "Data have been stored";
			cin.get();
			break;
		case 2:
			system("cls");
			MHD.printData(HT);
			MHD.editData(HT);
			cout << "Data have been saved";
			cin.get();
			break;
		case 3:
			system("cls");
			MHD.printData(HT);
			MHD.removeData(HT);
			cout << "Data have been removed";
			cin.get();
			break;
		case 4:
			MHD.printData(HT);
			break;
		case 5:
			system("cls");
			FM.ReadArticles("Articles.txt",HT);
			cout << "Articles have been read";
			cin.get();
			break;
		case 6:
			system("cls");
			FM.SaveArticles("Articles.txt",HT);
			cout << "Articles have been saved";
			cin.get();
			break;
		case 7:
			go = false;
			break;
		default:
			go = true;
			break;
		}
	}
	cin.get();
	return 0;
}