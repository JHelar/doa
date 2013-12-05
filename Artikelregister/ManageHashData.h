#pragma once

#include <iostream>
#include <string>

#include "Hashtable.h"
#include "HashData.h"
#include "Article.h"

class ManageHashData
{
public:

	ManageHashData(void)
	{
	}

	~ManageHashData(void)
	{
	}

	void removeData(Hashtable<string,Article> *HT)
	{
		string art;

		(*HT).print();
		cout << "Which article do you want to remove?,<name>: ";
		getline(cin,art,'\n');
		(*HT).remove((*(*HT).search(art)).info);
		return;
	}

	void addData(Hashtable<string,Article> *HT)
	{
		string dummy;
		Data<string,Article> data;

		cout << "Article name: ";
		getline(cin,dummy,'\n');
		data.info.setName(dummy);
		data.key = dummy;
		dummy.clear();
		cout << "Article type: ";
		getline(cin,dummy,'\n');
		data.info.setType(dummy);

		(*HT).add(data);
		return;
	}

	void editData(Hashtable<string,Article> *HT)
	{
		string art;
		string edit;


		(*HT).print();
		cout << "Which article do you want to edit?,<name>: ";
		getline(cin,art,'\n');
		
		cout << "What do you want to edit?, <type / name>: ";
		getline(cin,edit,'\n');
		if(edit.compare("type") == 0)
		{
			cout << "Set new type: ";
			getline(cin,edit,'\n');
			(*(*HT).search(art)).info.setType(edit);
			return;
		}
		else if(edit.compare("name") == 0)
		{
			cout << "Set new name: ";
			getline(cin,edit,'\n');
			(*(*HT).search(art)).info.setName(edit);
			return;
		}
	}

	void printData(Hashtable<string,Article> *HT)
	{
		cout << (*HT).print();
		cout << "Press enter to return";
		cin.get();
		return;
	}
};

