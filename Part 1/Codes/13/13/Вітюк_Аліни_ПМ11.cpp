#include<iostream>
using namespace std;
int main()
{
	int n, s = 0;
//��� ������ 
	do
	{
		cout << "Vvedit kilkist k = "; cin >> n;
		cin.seekg(0, ios::end);
		cin.clear();
	} while (n < 1);
//����������� ���� ���� ������ k
	do
	{
		s = s + n % 10;
		n = n / 10;
	} while (n > 0);
//���� ���������� 
	cout << "\nS = " << s;
	return 0;
}