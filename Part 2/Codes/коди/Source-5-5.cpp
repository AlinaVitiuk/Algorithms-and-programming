/* ������������ ������ */
#include <iostream>
#include <string.h> /* ������ ���� ������� strcat() */
#pragma warning(disable:4996);
using namespace std;
#define SIZE 80
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	puts("What is your favorite flower?");
	cin.getline(flower, SIZE - 1); /* ������� �� �����, �� ����� SIZE-1 ������� */
	strcat(flower, addon); /* ���� ������ addon ���������� � ����� ������ flower */
	puts(flower); /* ���� ������ flower - �� ��'������� ���� ������*/
	puts(addon); /* ����� ������ �� ���������*/
	puts("bye!");
	return 0;
}