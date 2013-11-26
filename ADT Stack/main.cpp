#include <iostream>

#include "Stack.h"

using namespace std;

int main(void)
{
	Stack<int> s;

	cout << "Adding number to the stack in order:\n ";
	for(int i = 0; i <= 10; i++)
	{
		cout << i << "\n";
		s.AddToStack(i);
	}
	cout << "Poping numbers from stack: \n";
	for(int i = 0; i <= 10; i++)
	{
		cout << s.PopFirst() << "\n";
	}
	cin.get();
	return 0;
}