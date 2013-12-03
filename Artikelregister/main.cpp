#include <iostream>

#include "Hashtable.h"
#include "HashData.h"

int main(void)
{

	Hashtable<string,int> ht(7,2,"",-1);
	ht.add(Data<string,int>("APA",1));
	ht.add(Data<string,int>("CHIMPANS",2));
	ht.add(Data<string,int>("GORILLA",3));
	ht.add(Data<string,int>("ÅKERÖ",4));
	ht.add(Data<string,int>("INGRID MARIE",5));
	ht.add(Data<string,int>("GOLDEN DELICIOUS",6));
	ht.add(Data<string,int>("TRANSPARANT",7));
	ht.add(Data<string,int>("A",8));
	ht.add(Data<string,int>("B",9));
	ht.add(Data<string,int>("C",10));
	ht.add(Data<string,int>("D",11));
	ht.add(Data<string,int>("E",12));
	ht.add(Data<string,int>("F",13));
	cout << ht.print();
	cin.get();
	return 0;
}