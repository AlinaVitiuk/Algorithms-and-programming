/* ������� 3 */
/* ��������-��������� ���������� � ���� ����� ���� ``���������'' */
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
	/* �������� ���������� � ���� ����� */
	cout << "\n����i�� ���i ��� ������ det:\n";
	cout << "\n ����� �����i = "; cin >> det.model_number;
	cout << "\n ����� �����i = "; cin >> det.detail_number;
	cout << "\n ����i��� �����i = "; cin >> det.detail_price;
	/* ��������� ���������� ���� ����� */
	cout << "\n����� �����i det : " << det.model_number << "\n����� �����i : "
		<< det.detail_number << "\n����i��� �����i : " << det.detail_price << " ���.\n";
	return 0;
}