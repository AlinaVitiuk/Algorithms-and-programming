/* ������� 1 */
/* ���������� ������ ���'��, ���� ����� ����� ���� ``���������'' � �� */
#include <iostream>
using namespace std;
int main()
{
	struct stuff /* ���������� ������� ��������� */
	{
		int number; /* 4 ����� */
		char code[4]; /* 4 �� 1 �����*/
		float cost; /* 4 �����*/
	} a1;
	cout << "sizeof a1 =" << sizeof(a1) << "\n";
	return 0;
}