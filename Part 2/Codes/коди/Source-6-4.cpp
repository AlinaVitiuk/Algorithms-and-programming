/* ������� 4 */
/* �������� ��� ����������� */
#include <iostream>
#include<Windows.h>
using namespace std;

struct detail
{
	int model_number; /* ����� �����*/
	int detail_number; /* ����� �����*/
	float detail_price; /* ������� �����*/
};

void main()
{
	SetConsoleOutputCP(1251); /* ���� ��������� ��� ������������ �������� ��� ���� �� ����� */
	SetConsoleCP(1251);
	struct detail det, det1 = { 12089,245,187.57f }, det2;
	cout << "\n����i� ������ ���� detail = " << sizeof(det) << " ����i�.\n";
	cout << "\n����� �����i det1 : " << det1.model_number << "\n����� �����i : "
		<< det1.detail_number << "\n����i��� �����i : " << det1.detail_price << " ���.\n";

	det2 = det1; /* ��������� ���� ����� �������� ���� ���������� ����� */
	detail*pd = &det1; /* ��������� ������ ���������� ����� */
	det = *pd; /* ��������� �������� ����� �� ������� ����� ���������� ����� */
	det.detail_number = 125; /* ��������� �������� ���� ���������� ����� */
	pd = &det; /* ��������� ������ ���������� ����� */

	cout << "\n����� �����i det : " << det.model_number << "\n����� �����i : "
		<< pd->detail_number << "\n����i��� �����i : " << pd->detail_price << " ���.\n";
	cout << "\n����� �����i det2 : " << det1.model_number << "\n����� �����i : "
		<< det1.detail_number << "\n����i��� �����i : " << det1.detail_price << " ���.\n";

	pd = new detail;
	(*pd).detail_number = 101; /* ������� ��������� ���� �������� �� �������, �� � ���������� */
	pd->detail_number = 12101; /* ������� ��������� ���� �������� �� �������, �� � ���������� */
	pd->detail_price = 256.08f;

	cout << "\n�����  ���� �����i : " << pd->model_number << "\n����� �i�� �����i : "
		<< pd->detail_number << "\n����i��� �����i : " << pd->detail_price << " ���.\n";
}