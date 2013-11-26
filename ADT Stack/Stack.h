#pragma once

#include <iostream>

#include "Node.h"

using namespace std;

template <class T>
class Stack
{
private:
	Node<T> *head;
public:

	Stack(void)
	{
		head=nullptr;
	}

	~Stack(void)
	{
		Node<T> *temp = head;
		Node<T> *n = temp;

		while(temp != nullptr)
		{
			n = temp;
			temp = temp->next;
            delete n;
		}
	}

	void AddToStack(T info)
	{
		if(head == nullptr)
			head = new Node<T>(info);
		else
		{
			Node<T> *temp = head;
			head = new Node<T>(info);
			head->next = temp;
		}
	}

	T PopFirst()
	{
		if(head == nullptr)
			cout << "STACK EMPTY!";
		else
		{
			if(head->next == nullptr)
			{
				T info = head->info;
				delete head;
				head = nullptr;
				return info;
			}
			else
			{
				Node<T> *temp = head->next;
				T info = head->info;
				delete head;
				head = temp;
				return info;
			}
		}
	}
};

