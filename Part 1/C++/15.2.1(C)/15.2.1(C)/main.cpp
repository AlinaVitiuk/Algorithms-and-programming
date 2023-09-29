//15.2.1(C)
//Вводиться набір з k дійсних чисел. 
//Обчислити середнє арифметичне набору.
#include<iostream>
using namespace std;
int main()
{
	int k, s = 0, v;
	do
	{
		cout << "Vvedit kilkist k = "; cin >> k;
	} while (k <= 0);
	double x;
	for (int i = 0; i < k; i++)
	{
		cout << "\nVvedit element x = "; cin >> x;
		s = s + x;
	}
	v = s / k;
	cout << "v=" << v;
	return 0;
}