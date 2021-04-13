#include "std_lib_facilities.h"

int main()
{
	int x1 = 7;
	int* p1 = new int;
	*p1 = x1;
	cout << "x1=" << x1 << ",adress of x1=" << &p1 << endl;
	int array[7]{ 1,2,3,4,5,6,7 };
	int*p2 = array;
	cout << "p2=" << *p2 << ",adress of array=" << &p2 << endl;
	int* p3 = p2;
	p2 = p1;
	p2 = p3;
	cout << "p1=" << *p1 << ",adress of p1=" << &p1 << endl;
	cout << "p2=" << *p2 << ",adress of p2=" << &p2 << endl;
	delete[]p2;//Delete this code if it crashes then run again
	delete p1;//Delete this code if it crashes then run again
	system("pause");
	return 0;
}