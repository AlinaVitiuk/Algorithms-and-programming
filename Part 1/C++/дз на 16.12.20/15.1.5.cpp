//15.1.5
//Визначити, чи з чотирьох чисел a, b, c, d є хоча б одна пара рівних між собою.
#include<iostream>
using namespace std;
int main()
{
	float a, b, c, d;
	cout << "Are there equal numbers?" << endl;
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;	
	cout << "c="; cin >> c;
	cout << "d="; cin >> d;
	if (a == b)
	{
		cout << "yes" << endl;
	}
	else
	if (a == c)
	{
		cout << "yes" << endl;
	}
	else
	if (a == d)
	{
		cout << "yes" << endl;
	}
	else
	if (b == c)
	{
		cout << "yes" << endl;
	}
	else
	if (b == d)
	{
		cout << "yes" << endl;
	}
	else

	if (c == d)
	{
		cout << "yes"<<endl;
	}
	else
	{
		cout << "no"<<endl;
	}
	return 0;
}