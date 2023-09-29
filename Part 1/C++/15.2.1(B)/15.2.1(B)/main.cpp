//15.2.1 (B)
//¬водитьс€ наб≥р з k д≥йсних чисел. 
//Oбчислити в≥дсоток чисел, що лежать в ≥нтервал≥ [m, n].
#include<iostream>
using namespace std;
int main()
{
	int k, s=0, v;
	do
	{
		cout << "Vvedit kilkist k = "; cin >> k;
	} while (k <= 0);
	int m, n;
	do
	{
		cout << "m="; cin >> m;
		cout << "n="; cin >> n;
	} while (m > n);
	double x;
	for (int i=0; i<k; i++)
	{
		cout << "\nVvedit element x = "; cin >> x;
		if (x<=n && x>=m)
		{
			s++;	
		}
	}
	v = (s*100)/k;
	cout << "vidsotok=" << v; cout << "%" << endl;
	
return 0;
}