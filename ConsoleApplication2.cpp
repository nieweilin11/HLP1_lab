#include "std_lib_facilities.h"
double pemuti(double A, double B)
{
	unsigned long long factorial = 1;
	for (int i = 1; i <= A; ++i)
	{
		factorial *= i;
		A = i;
	}
	for (int i = 1; i <= B; ++i)
	{
		factorial *= i;
		B=i;
	}
	return A/(A*B);
	
}

double combin(double A, double B)
{
	unsigned long long factorial = 1;
	for (int i = 1; i <= A; ++i)
	{
		factorial *= i;
		A = i;
	}
	for (int i = 1; i <= B; ++i)
	{
		factorial *= i;
		B = i;
	}
	return (A / (A * B)) / B;
}

int main()
{
	int a, b;
	int c = 0;
	try {
		cout << "Please enter number a and b" << endl;
		cin >>a>>b;
		if (a == 0 || b == 0)
			error("Input number cannot be Zero!");
		if (a * c != 0 || b * c != 0)
			throw - 1;
	     }
	catch (int e)
	{
		cout << "a or b is not a number" << endl;
	}
	char op = 'a';
	cout << "Please choose Permutation  Combination or both of them by enter (P or C or T )" << endl;
	switch (op) {
	case'P':
		cout << "P=" << pemuti(a, b) << endl;
		break;
	case'C':
		cout << "C=" << combin(a, b) << endl;
		break;
	case'T':
		cout << "P=" << pemuti(a, b) << "C=" << combin(a, b) << endl;
	default:
		cout << "Don't konw the operation" << endl;
		break;
	}

	return 0;
}
	   