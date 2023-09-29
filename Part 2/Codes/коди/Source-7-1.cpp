/* ������� 1 */
/* ������� ��������� */
#include<iostream>
#include<Windows.h>
#include<string.h> /* ������ ��������� ��������� ������� */
#pragma warning(disable:4996) 
/* ��������� ��� ��������� ��������� ���������� -
�������� ������� ���� � ��������������� ������� ���������� */
using namespace std;
const int size_s = 20, k_ex = 5;
struct Date /* ���������, ��� ������ ���� */
{
	int Day, Month, Year; /* ����, �����, �� */
};
struct FullName /* ���������, ��� ������ ����� ��'� �������� */
{
	char FirstName[size_s], LastName[size_s]; /* ��'� �� ������� �������� */
};
struct Person /* �������� ���������, ��� ������ ��� ��� ����� */
{
	struct FullName Name; /* ����� ��'� */
	struct Date BirthDate; /* ���� ���������� */
	char Sex; /* ����� */
};
struct STUDENT /* �������� ���������, ��� ������ ���������� ��� �������� */
{
	struct Person Pers; /* ��� ��� ����� */
	struct Date AdmissionDate; /* ���� ������ � ��� */
	int Marks[k_ex]; /* ����� ������ */
};
void main()
{
	SetConsoleOutputCP(1251); /* ���� ��������� ��� ������������ �������� ��� ���� �� ����� */
	SetConsoleCP(1251);
	STUDENT a = { {{"������","�������"}, {2,12,2000}, 'f'}, {12,7,2018}, {3,4,5,5,4} };
	/* ���������� �� ����������� ����� a ���� ``���������'' STUDENT */
	cout << "����i� ��������� STUDENT = " << sizeof(STUDENT) << endl;
	/* ����� �����, ���� ��������� ����� ���� ``���������'' STUDENT */
	cout.width(size_s / 2); cout << a.Pers.Name.LastName;
	/* ������ ��� ���������� ������ ���� ������� size_s/2 ������� */
	/* � �������� �� ����� ������� ��������*/
	cout.width(size_s / 2); cout << a.Pers.Name.FirstName << "   ";
	/* ������ ��� ���������� ������ ���� ������� size_s/2 ������� */
	/* � �������� �� ����� ��'� ��������*/
	cout.fill('0'); /* �������� ����� ���� ��� ���������� ������ �������� '0' */
	cout.width(2); cout << a.Pers.BirthDate.Day << '-';
	cout.width(2); cout << a.Pers.BirthDate.Month << '-' << a.Pers.BirthDate.Year;
	/* �������� �� ����� ���� ���������� �������� */
	cout.fill(' '); /* �������� ����� ���� ��� ���������� ������ �������� ' ' */
	cout.width(4); cout << a.Pers.Sex << "   "; /* �������� �� ����� ����� �������� */
	cout.fill('0'); cout.width(2); cout << a.AdmissionDate.Day << '-'; 
	cout.width(2); cout << a.AdmissionDate.Month << '-' << a.AdmissionDate.Year;
	/* �������� �� ����� ���� ����������� �������� �� ��� */
	cout.fill(' ');
	for (int j = 0; j < k_ex; j++) /* �������� �� ����� �� ������ ��������*/
		cout.width(5), cout << a.Marks[j];
	cout << "\n\n";

	/* ���� ������ ���� � ��������� ���������� */
	a.Marks[0] = 5; /* ���������� ����� */
	strcpy(a.Pers.Name.LastName, "�������");	/* ���� ������� */
	cout << "\n���i ���i\n"; /* �������� �������� ���������� */
	cout.width(size_s / 2); cout << a.Pers.Name.LastName;
	cout.width(size_s / 2); cout << a.Pers.Name.FirstName << "   ";
	cout.fill('0'); cout.width(2); cout << a.Pers.BirthDate.Day << '-';
	cout.width(2); cout << a.Pers.BirthDate.Month << '-' << a.Pers.BirthDate.Year; cout.fill(' ');
	cout.width(4); cout << a.Pers.Sex << "   ";
	cout.fill('0'); cout.width(2); cout << a.AdmissionDate.Day << '-'; cout.width(2);
	cout << a.AdmissionDate.Month << '-' << a.AdmissionDate.Year; cout.fill(' ');
	for (int j = 0; j < k_ex; j++)
		cout.width(5), cout << a.Marks[j];
	cout << "\n\n";
}