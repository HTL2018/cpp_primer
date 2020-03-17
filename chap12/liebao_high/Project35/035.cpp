#include <iostream>
#include "QueueLi.h"

using namespace std;

int main()
{

	cout << "²âÊÔÁ´Ê½¶ÓÁÐ£º " << endl;

	Queue<int> myQ;

	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);

	cout << myQ.getFront() << endl;//10
	myQ.dequeue();
	cout << myQ.getFront() << endl;//20
	cout << myQ.dequeue() << endl;//20
	cout << myQ.dequeue() << endl;//30

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
			myQ.enqueue(i);

		while (!myQ.isEmpty())
		{
			cout << myQ.dequeue() << endl;
		}
	}

	return 0;
}