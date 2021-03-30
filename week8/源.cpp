#include "std_lib_facilities.h"

int main(){
	vector<double>var;
	double num;
	try {
		cout << "please enter the name of  the input file " << endl;
		string iname;
		cin >> iname;
		ifstream file{ iname };//读取文件
		if (!file)
			error("Do not found such file ");
			while (file>> num) {
				var.push_back(num);//读取数字
			}
		}
	
	catch (exception& e) {
		cout << e.what() << endl;
		return 1;
	}
	double sum =0;
	for (int i = 0; i < var.size();i++) {//把数加起来
		sum+=var[i];
	}
	cout << "sum="<<sum<<endl;
	return 0;
}