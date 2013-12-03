#pragma once

#include <iostream>

using namespace std;
template <class KEY,class INFO>
struct Data
{
	KEY key;
	INFO info;

	Data(){}
	Data(KEY key,INFO info)
	{
		this->key = key;
		this->info = info;
	}
};