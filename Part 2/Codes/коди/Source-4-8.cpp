#include<iostream>
const int size1 = BUFSIZ;
using namespace std;
void main()
{
	char str1[size1];
	puts("Vvod'te strichku");
	gets_s(str1);
	//����� ������ str1 ������� ����
	//�������� ��� ������ ������� ����������
	puts("\n Vvedena strichka");
	puts(str1);
}