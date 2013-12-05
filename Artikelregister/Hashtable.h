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
		Data<KEY,INFO> temp("",INFO());

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
				return &data;
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
		Data<KEY,INFO> emptyData("",INFO());
		for(int i = 0; i < (*overflow).size(); i++)
		{
			if((*overflow)[i].info == info)
			{
				(*overflow)[i] = emptyData;
				return;
			}
		}

		Data<KEY,INFO> *data = this->search(info);
		long indx = this->getIndex((*data).key);

		(*table)[indx +1] = emptyData;
		return;
	}

	void saveHash(ostream &out)
	{
		for(int i = 0; i < primeNumber; i++)
		{
			for(int j = 0; j < bucketSize; j++)
			{
				if(((*table)[i * bucketSize + j]).key != "")
					out << ((*table)[i * bucketSize + j]).info << endl;
			}
		}
		for(auto data : *overflow)
		{
			if(data.key != "")
				out << data.info << endl;
		}
	}

	string print()
	{
		ostringstream oss;

		for(int i = 0; i < primeNumber; i++)
		{
			for(int j = 0; j < bucketSize; j++)
			{
				oss << ((*table)[i * bucketSize + j]).info << endl;
			}
		}
		for(auto data : *overflow)
		{
			oss << data.info << endl;
		}
		return oss.str();
	}

	int getPrimeNumber(){return this->primeNumber;}
	int getBucketSize(){return this->bucketSize;}

	~Hashtable(void)
	{
		delete table;
		delete overflow;
	}
};

