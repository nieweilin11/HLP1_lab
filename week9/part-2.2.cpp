#include "std_lib_facilities.h"

int main()
{

	int array_1[10]{ 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = new int[10];
	for (int i = 0; i < 10; i++)
		p1[i] = array_1[i];
	int* p2 = new int[10];
	for (int i = 0; i < 10;i++) {
		p2[i] = p1[i];
		cout << p2[i] << endl;
	}
	cout << "p2=" << *p2 << ",adress of p2=" << &p2 << endl;
	delete[]p1;//Delete this code if it crashes then run again
	delete[]p2;//Delete this code if it crashes then run again
system("pause");
return 0;
}