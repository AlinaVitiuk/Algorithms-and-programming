#include<iostream>      // �������������� ��'�������� ���� stdio.h
#include<string.h>      // ������ ��������� ��������� ������� 
#include <ctype.h>      // ������ �������, �� ������������ ������������ ������� �� �������� �����
#include <Windows.h>    // ���������� ����������� �����

using namespace std;
const int size1 = 100; //
void main()
{
	SetConsoleOutputCP(1251);    //������������ ��������� Windows-1251 ��� ��������� �����
	SetConsoleCP(1251);          //������������ ��������� Windows-1251 ��� �������� �����
	char c_end = '.';            //������ ���������� �����
	char str[size1] = " ";       //������� ����� ������� ��������� size1
	int n = size1 - 1; int i = 0;
	cout << "\n������ �����\n";
	cout << "\nϳ��� �������� �������� ������ ������ � . � �� �������� ENTER\n";
	while (i < n && ((str[i] = getchar()) != c_end))i++;
	str[i] = '\0'; n = i;
	cout << "\n�������� ����� �� " << (n) << " �������\n" << str << endl;

}