//15.2.1(D)
//¬водитьс€ наб≥р з k д≥йсних чисел. 
//«найти м≥н≥мальний елемент у набор≥.
#include<iostream>
using namespace std;
int main()
{
	int k, s = 0;
	do
	{
		cout << "Vvedit kilkist k = "; cin >> k;
	} while (k < 1);
	int i = 1;
	double x, min;
	cout << "\nVvedit element x = "; cin >> x;
	min = x;
	i++;
	for (; i <= k; i++)
	{
		cout << "\nVvedit element x = "; cin >> x;
		if (x < min)
		{
			min = x;
		}
	}
	cout << "\nMinimalnui element u nabori = " << min;
		return 0;
}