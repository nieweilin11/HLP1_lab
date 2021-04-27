#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int x)
{
	for (int i = 0; i < x; i++)
		os << a[i] << endl;
}
int main()
{
	int n = 10;
	int* parr = new int[10];
	cout << "array_10" << endl;
	for (int k = 0; k < n; k++)
	{
		parr[k] = 100 + k;
	}
	ostream& os = cout;
	print_array(os, parr, n);

	delete[]parr;

	int* array_11 = new int[11];
	int n_1 = 11;
	cout << "array_11" << endl;
	for (int i = 0; i < n_1; i++)
	{
		array_11[i] = 100 + i;
		cout << array_11[i] << endl;
	}
	delete[]array_11;
	int* array_20 = new int[11];
	int n_2 = 11;
	cout << "array_20" << endl;
	for (int i = 0; i < n_2; i++)
	{
		array_20[i] = 100 + i;
		cout << array_20[i] << endl;
	}

	delete[]array_20;

	cout << "vector_10" << endl;
	vector<int>* v = new vector<int>[10];
	int x = 10;
	for (int i = 0; i < x; i++) {
		v->push_back(i);
		cout << v->at(i) << endl;
	}
	delete[]v;
	cout << "vector_11" << endl;
	vector<int>* v_11 = new vector<int>[11];
	int x_1 = v_11->size();
	for (int i = 0; i < x_1; i++) {
		v_11->push_back(i);
		cout << v_11->at(i) << endl;
	}
	delete[]v_11;
	cout << "vector_20" << endl;
	vector<int>* v_20 = new vector<int>[20];
	int x_2 = v_20->size();
	for (int i = 0; i < x_2; i++) {
		v_20->push_back(i);
		cout << v_20->at(i) << endl;
	}
	delete[]v_20;
	system("PAUSE");
	return 0;
}