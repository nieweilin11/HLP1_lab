#include "std_lib_facilities.h"
#include <iostream>
void x(double A, double B, double C)
{
	if (B * B - 4 * A * C < 0) throw Fail{};
	return (-B-sqrt(B*B-4*A*C))/2*A;
}


int main()
{
	double a, b, c;
	try {
    cin >> a >> b >> c;
	cout << x(a, b, c) << endl;
	  }
	catch (Fail)
	{
		cout << "Fail" << endl;
	}
}



