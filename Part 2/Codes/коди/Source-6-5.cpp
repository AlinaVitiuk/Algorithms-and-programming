/* ������� 5 */
/* ����� �������� ��������� ����� �� ����� */
#include <iostream>
#include<Windows.h>
using namespace std;

struct Point_2d /* ���������� ������� ��������� */
{
	int left, top; /* ���������� �����*/
};

const int size1 = 100; /* ������� ��������� ��������� ������ */

int vvid_chusla(const char*); /* �������� ������� ��� �������� ����� � ���������*/

void main()
{
	SetConsoleOutputCP(1251); /* ���� ��������� ��� ������������ �������� ��� ���� �� ����� */
	SetConsoleCP(1251);
	int n;
	struct Point_2d screen[size1]; /* ���������� ���������� ������ �������� */
	do
	{
		n = vvid_chusla(" �i���i��� ����� �� �����i ");
	} while (n <= 0 || n > size1);
	//Point_2d* screen = new Point_2d[n]; /*����� ��������� ��������� ����� ��������*/
	cout << "\n ������� ���������� ����� �i������ �i���� ��������� ���� ������\n\n";
	for (int i = 0; i < n; i++)
	{
		screen[i].left = vvid_chusla(" ��i�� ");
		screen[i].top = vvid_chusla(" ������ ");
	}
	cout << "\n����� ������\n";
	for (int i = 0; i < n; i++)
	{
		cout << " \n����� [" << i + 1 << "] = (";
		cout.width(3);  cout << (screen + i)->left << ",";
		cout.width(3);  cout << screen[i].top << " )";
	}
	cout << endl;
}
int vvid_chusla(const char*ms) /* ������� ��� �������� ����� � ���������*/
{
	cout << "����i�� " << ms << " = ";
	char rez[10]; /* ����� ������� ��� ���������� ������� ������ */
	cin.getline(rez, 10);
	return atoi(rez); /* ������������ ������ �� ������ ����� */
}