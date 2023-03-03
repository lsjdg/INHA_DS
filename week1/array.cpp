#include <iostream>
#include "array.h"
using namespace std;

int main()
{
	Array array(10);
	//#1
	array.add(0, 5);
	array.print();

	array.remove(0);
	array.print();

	array.set(1, 10);
	array.print();

	array.set(2, 10);
	array.set(7, 7);
	array.print();

	cout << array.find(10) << " " << array.find(7) << '\n';


	//#2
	array.rightShift(14);
	array.print();
	
	Array arr(8);
	for (int i{ 0 }; i < 8; i++)
	{
		arr.set(i, i);
	}
	arr.print();
	arr.reverse(3, 7);
	arr.print();
}