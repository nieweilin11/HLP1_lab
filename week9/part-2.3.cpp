#include "std_lib_facilities.h"
int main() {
	cout << "vector part" << endl;
	vector<int>* p = new vector<int>[10];
	for (int i = 0; i < 10; i++)
		p->push_back(i);
	vector<int>* q = new vector<int>[10];
	int x = p->size();
	for (int i = 0; i < x; i++) {
		q->push_back(p->at(i));
		cout << q->at(i) << endl;
	}
	delete[]p;
	delete[]q;
	system("pause");
	return 0;
}