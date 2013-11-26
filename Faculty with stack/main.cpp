#include <iostream>

#include "Stack.h"

void FacultyStack(int i)
{
	Stack<int> dummy;
	int n = 0;
	n = i;
    dummy.AddToStack(n);
    while(i > 1)
    {
		n = n*(i-1);
		dummy.AddToStack(n);	
        i--;
    }
    cout << dummy.str();
}

int main(void)
{
	FacultyStack(10);
	cin.get();
	return 0;
}