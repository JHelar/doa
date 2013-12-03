#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include "HashData.h"

using namespace std;
template <class KEY,class INFO>
class Hashtable
{
private:
	int bucketSize;
	int primeNumber;
	vector<Data<KEY,INFO>> *table;
	vector<Data<KEY,INFO>> *overflow;
	hash<KEY> h;

	long hash(KEY key)
	{
		return (h(key) % primeNumber);
	}
public:

	Hashtable(){}

	Hashtable(int primeNumber, int bucketSize, KEY key, INFO info)
	{
		this->primeNumber = primeNumber;
		this->bucketSize = bucketSize;

		table = new vector<Data<KEY,INFO>>(primeNumber * bucketSize);
		for(auto &data : *table)
		{
			data = Data<KEY,INFO>(key,info);
		}
		overflow = new vector<Data<KEY,INFO>>();
	}

	void setHashTable(int primeNumber, int bucketSize, KEY key, INFO info)
	{
		this->primeNumber = primeNumber;
		this->bucketSize = bucketSize;

		table = new vector<Data<KEY,INFO>>(primeNumber * bucketSize);
		for(auto &data : *table)
		{
			data = Data<KEY,INFO>(key,info);
		}
		overflow = new vector<Data<KEY,INFO>>();
	}

	long getIndex(KEY key)
	{
		return hash(key) * bucketSize;	
	}

	void add(Data<KEY,INFO> data)
	{
		long indx = getIndex(data.key);
		Data<KEY,INFO> temp("",0);

		for(int i = 0; i < bucketSize; i++)
		{
			if((data.key != temp.key) && (temp.key == (*table)[indx + i].key))
			{
				(*table)[indx + i] = data;
				return;
			}
		}
		(*overflow).push_back(data);
		return;
	}

	Data<KEY,INFO> *search(KEY key)
	{
		long indx = getIndex(key);
		for(int i = 0; i < bucketSize; i++)
		{
			if(((*table)[indx + i]).key == key) 
				return &((*table)[indx + i]);
		}

		for(auto &data : *overflow)
		{
			if(data.key == key)
				return &d;
		}

		return nullptr;
	}

	Data<KEY,INFO> *search(INFO info)
	{
		for(auto &data : *table)
		{
			if(data.info == info)
				return &data;
		}

		for(auto &data : *overflow)
		{
			if(data.info == info)
			{
				return &data;
			}
		}

		return nullptr;
	}
	
	void remove(INFO info)
	{
		Data<KEY,INFO> *data = this->search(info);
		Data<KEY,INFO> emptyData
		long indx = this->getIndex((*data).key);

		(*table).erase((*table).begin() + indx);
	}

	string print()
	{
		ostringstream oss;
		oss << "Hash contents: \n";
		for(int i = 0; i < primeNumber; i++)
		{
			oss << "Hash table: \n";
			for(int j = 0; j < bucketSize; j++)
			{
				oss << ((*table)[i * bucketSize + j]).key << ": " << ((*table)[i * bucketSize + j]).info << endl;
			}
		}

		oss << "Overflow: \n";
		for(auto data : *overflow)
		{
			oss << data.key << ": " << data.info << endl;
		}

		return oss.str();
	}

	~Hashtable(void)
	{
		delete table;
		delete overflow;
	}
};

