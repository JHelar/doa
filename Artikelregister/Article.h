#pragma once

#include <iostream>
#include <string>

#include "Hashtable.h"

using namespace std;
class Article
{
protected:
	string name;
	string type;
public:

	Article(void)
	{
		this->name = ""; 
		this->type = "";
	}

	Article(string name, string type)
	{
		this->name = name;
		this->type = type;
	}

	~Article(void)
	{
	}

	string getName(){return this->name;}
	void setName(string name){this->name = name;}

	string getType(){return this->type;}
	void setType(string type){this->type = type;}

	friend istream& operator >> (istream &in, Article &article)
	{
		char c;

		in >> c;
		getline(in,article.type,',');
		getline(in,article.name,')');
		return in;
	}

	friend ostream& operator << (ostream &out, Article article)
	{
		out << "(" << article.type << "," << article.name << ")";
		return out;
	}

	friend bool operator == (Article &one, Article &another)
	{
		if(one.type.compare(another.type) == 0)
			if(one.name.compare(another.name) == 0)
				return true;
		return false;
	}

	friend bool operator != (Article &one, Article &another)
	{
		if(one == another)
			return false;
		else
			return true;
	}
};

