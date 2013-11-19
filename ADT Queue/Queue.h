#pragma once

#include <iostream>

using namespace std;

template <class INFO>
struct Node
{
	INFO info;
	Node<INFO> *next;
};

template <class T>
class Queue
{
private:

	Node<T> *head;
	Node<T> *tail;

public:
	Queue()
	{
		head=tail=nullptr;
	}

	Queue(Node<INFO> start)
	{
		tail = head = new Node<INFO>(start);
	}
};

