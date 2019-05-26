#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<double> s;
	for (int i = 0; i < 10; i++)
	{
		s.Push(i * 3.5);
		cout << "count = " << s.getCount() << endl;
		s.Print();
		cout << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		s.Pop();
		cout << "count = " << s.getCount() << endl;
		s.Print();
		cout << endl;
	}
	system("pause");
}
