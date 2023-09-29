/* ������� 6 */
/* ����� �������� � ����������� ��� �������� ����� */
#include<iostream>
#include <Windows.h>
using namespace std;

const int size_s = 20, size_ex = 5;

struct student
{
	/* ������ ������� ��� ��������� ���� �� ������� ��������*/
	char FirstName[size_s], LastName[size_s];
	/* ����� ������������� ������ */
	int Marks[size_ex];
};

void main()
{
	SetConsoleOutputCP(1251); /* ���� ��������� ��� ������������ �������� ��� ���� �� ����� */
	SetConsoleCP(1251);
	/* ����������� ������ �������� */
	struct student group[] = { {"����i�","�����",{5,4,4,5,4}},
				   {"�����","�������",{5,5,4,4,4}},
				   {"����i�","������",{3,4,4,5,4}},
				   {"������","�������",{5,5,5,5,3}}
	};
	/* ���������� ������� �������� ������ ��������*/
	int n = sizeof(group) / sizeof(student);
	/* ������� ������� ���� �������� ������ ��������*/
	cout << "\n���������� ���i�:\n\n";
	for (int i = 0; i < n; i++)
	{
		/* ����������� ��������� ���������� */
		cout.width(size_s); cout << (group + i)->LastName;
		/*���*/
		//cout << (*(group + i)).LastName;
		cout.width(size_s); cout << group[i].FirstName;
		for (int j = 0; j < size_ex; j++)
		{
			cout.width(5); cout << (group + i)->Marks[j];
		}
		cout << endl;
	}
}
