#include "std_lib_facilities.h"


int main()
{
	int x = 7;
	int* p1 = new int;
	*p1 = x;
	cout << "p1=" << *p1 << ",adress of 7=" << &p1 << endl;
	int array[7]{ 1,2,3,4,5,6,7 };
	int* p2 ;
	p2 = array;
	cout << "p2=" << *p2 << ",adress of array=" << &p2 << endl;
	int* p3 = p2;
	p2 = p1;
	p2 = p3;
	cout << "p1=" << *p1 << ",adress of p1=" << &p1 << endl;
	cout << "p2=" << *p2 << ",adress of p2=" << &p2 << endl;
	p1 = nullptr;
	p2 = nullptr;

	cout << "________________________________________" << endl;
	int array_1[10]{ 1,2,4,8,16,32,64,128,256,512 };
	int* p_1 = array_1;
	int* p_2 = new int[10];
	for (int i = 0; i < 10; i++) {
		p_2[i] = p_1[i];
		cout << p_2[i] << endl;
	}
	cout << "p2=" << *p_2 << ",adress of p2=" << &p_2 << endl;
	p_1 = nullptr;
	p_2 = nullptr;
	cout << "________________________________________" << endl;
	cout << "vector part" << endl;
	vector<int>* p = new vector<int>[10];
	for (int i = 0; i < 10; i++)
		p->push_back(i);
	vector<int>* q = new vector<int>[10];
	int x_1 = p->size();
	for (int i = 0; i < x_1; i++) {
		q->push_back(p->at(i));
		cout << q->at(i) << endl;
	}
	p = nullptr;
	q = nullptr;


	system("pause");
	return 0;
}