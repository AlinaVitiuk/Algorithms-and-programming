/* ������� 2 */
/* ����������� ����� ���� ``���������'' */
#include <iostream>
#include<Windows.h>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251); /* ���� ��������� ��� ������������ �������� ��� ���� �� ����� */
	SetConsoleCP(1251);
	struct detail /* ���������� ������� ��������� ������*/
	{
		int model_number; /* ����� �����*/
		int detail_number; /* ����� �����*/
		float detail_price; /* ������� �����*/
	};
	/* ���������� ������ �� ����������� ���� � ��� */
	detail det, det1 = { 12089, 245, 187.57f }, det2;
	/* ����������� ������ ���'��, ������� �� ����� det */
	cout << "\n����i� ������ ���� detail = " << sizeof(det) << " ����i�.\n";
	return 0;
}