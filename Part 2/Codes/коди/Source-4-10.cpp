#include<iostream>
const int size1 = 20;
using namespace std;
void main()
{
	SetConsoleOutputCP(1251);    //������������ ��������� Windows-1251 ��� ��������� �����
	SetConsoleCP(1251);          //������������ ��������� Windows-1251 ��� �������� �����
	char str1[size1];
	cout << "Vvedit sumvol kincia ";
	char c = cin.get();
	//������� ������� ������
	for (int i = 0; i < 2; i++)
	{
		//cin.ignore(1, '\n'); //������ '\n' ���������� � ������
		puts("Vvod'te strichku 1");
		cin.get(str1, size1);
		//������� ������ ������ �������
		puts("\nVvedena strichka 1"); puts(str1);
		puts("\nVvod'te strichku 2");
		cin.get(str1, size1, c);
		//������� ������ �� ���������� ������ �������
		//��� ��������� �������
		puts("\nVvedena strichka 2");
		puts(str1);
		//cin.ignore(1, c); //������ � ���������� � ������
	}
}