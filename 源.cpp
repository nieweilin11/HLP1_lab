#include "std_lib_facilities.h"

int main()
{
	char choose = ' ';
	cout << "please enter （e or d）to choose Encryption or Decryption " << endl;
	cin >> choose;
	switch (choose)
  {

	case'e':
	{  
		int num_input = 0;
		cout << "please enter a integer number to show how many number you want to Encrypt" << endl;
		if (num_input > 10 && num_input < 1)
			cout << "the line of number shoulde gearter equal than 1 and less equal than 10 " << endl;
		cin >> num_input;//读取输入数据长度
		vector<int>v_encry;
		int i = 0, temp = 0;
		for (int i = 0; i < num_input;i++)//读取整数
		{
			cout << "please enter a integer number" << endl;
			cin >> temp;
			v_encry.push_back(temp);

			
		}
		sort(v_encry);//排序
		
		for (int n = 0; n < v_encry.size();n++)//开始加密
		{
			int count=0;
			for (int i = 0; i < v_encry[n]; i++)//对每一个数进行加密
			{
				count++;
				cout << "1";
					
			}
			if (count = v_encry.size()-1)cout << "-";
	       
			
			
			
		}


	 
	}
	break;

	case'd':
	{
		int num_input = 0;
		cout << "please enter a integer number to show how many number you want to Encrypt" << endl;
		if (num_input > 10 && num_input < 1)
			cout << "the line of number shoulde gearter equal than 1 and less equal than 10 " << endl;
		cin >> num_input;//读取输入数据长度
		vector<int>v_deencry;
		int i = 0, temp = 0;
		for (int i = 0; i < num_input; i++)//读取整数
		{
			cout << "please enter a binary number" << endl;
			cin >> temp;
			v_deencry.push_back(temp);



		}
		sort(v_deencry);//排序
		for (int n = 0; n < v_deencry.size(); n++)//开始加密
		{
			
			int sum = 0;
			int temp = v_deencry[n];
			while (temp!= 0)
			{
				sum++;
				temp/=10;
		

			}
			if(n<v_deencry.size()-1)
			cout <<sum<<"-";
			else
		    cout << sum;

		




		}
		break;
	
	
	
	
	
	
	
	
	
	
	
	
	}

	default:
		cout << "Don't konw waht it is " << endl;
  
	
	
	}
	


	return 0;
}

