#pragma once
#include <iostream>

using namespace std;
template <class INFO>
struct Node
{
	INFO info;
	Node<INFO> *next;

	Node(INFO info){this->info = info; this->next = nullptr; }
};

