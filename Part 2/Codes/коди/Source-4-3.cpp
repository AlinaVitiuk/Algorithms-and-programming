#include<iostream>
using namespace std;
void main()
{
	char str1[10] = "Education";//��� �����
	//char str2[3] = "may";//��� �� �����
	char str3[] = "Initialization";//��� �����
	const char* str4 = "Knowledge";//��� �����
	//char *str5 = { 'H','e','l','l','o',',',' ','w','o','r','l','d','!','\0' };//��� �� �����
	//�� str5 - �� �������� �� ������, � �� �� ����� �������
	cout << str1 << '\n'  << '\n' << str3
		<< '\n' << str4 << '\n'  << '\n';
}