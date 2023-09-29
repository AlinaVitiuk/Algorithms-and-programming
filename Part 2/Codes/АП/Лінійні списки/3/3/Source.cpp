//������ ���������� ����� N.�������� ���� � ���� ���� �� ���������� ���� ���� �
//���� ������������

#include<iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

typedef long long dane; //������������ ��������� dane ��� ���� long long

struct stack //����������  �����
{
	dane info;
	stack* adr;
};

void AddtoStack(stack*&, dane);             //��������� ������ �������� �� �����
void PrintStack(stack*, const char*);       //���� �����
void DestroyStack(stack*&);                 //��������� �����
void SumDifferentNumbers(stack*, int);      //���������� ���� ����� ����
int main()
{
	SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����
	stack* top = NULL;
	dane n = 0;
	int k = 0;
	cout << "������ ���������� ����� N: ";
	cin >> n;
	if (n < 0)
		n = -n;
	int rd = 10;
	do
		AddtoStack(top, n % rd);
	while (n /= rd);
	cout << "\n";
	PrintStack(top, "���� ���� ����� N: ");
	SumDifferentNumbers(top, k);
	DestroyStack(top);
	return 0;
}

void AddtoStack(stack*& node, dane a) //��������� ������ �������� �� �����
{
	stack* prev = node;
	node = new stack;
	node->info = a;
	node->adr = prev;

}
void PrintStack(stack* node, const char* msg) //���� �����
{
	cout << msg << endl;
	while (node)
	{
		cout << node->info << ' ';
		node = node->adr;
	}
	cout << endl;
}
void DestroyStack(stack*& node) //��������� �����
{
	stack* next;
	while (node)
	{
		next = node->adr;
		delete node;
		node = next;
	}
}
void SumDifferentNumbers(stack* node, int n)
{
	int A[10]{ 0 };

	while (node) {
		A[node->info]++;
		node = node->adr;
	}
	cout << "��� ������ ����� N ���� ����������� ������� �����: ";
	for (int i = 0; i < 10; i++) {
		if (A[i] != 0) {
			n += i; //���� ����
			cout << i << " ";
		}
	}
	cout << "\n���� ���� � ������������ ����� N = " << n << endl;
}