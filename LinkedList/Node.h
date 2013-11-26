#pragma once

#include <iostream>

using namespace std;
/** Class Node, simple data node class for the List class */
template <class INFO>
class Node
{
public:

	INFO info;
	Node<INFO> *next;
	Node(void)
	{
		this->next = nullptr;
	}

	Node(INFO info)
	{
		this->info = info;
		this->next = nullptr;
	}

	~Node(void)
	{
	}
};

