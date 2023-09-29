//���������� ����� N ����������� � ������ ����� ���� ����.ϳ���������
//������ ����� ���� ����������� ��� ������ �����.

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
void DifferentNumbers(stack*, int, const char*); //���������� ������� ����� ����
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
	DifferentNumbers(top, k, "��� ������ ����� N �����������:");
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
void DifferentNumbers(stack* node, int n, const char* msg)
{
	int A[10]{ 0 };

	cout << "\n-----------------------------\n";
	cout << "| ����� | �-��� ����������� |\n";
	cout << "-----------------------------\n";

	while (node) {
		for (int i = 0; i < 10; i++) {
			if (node->info == i) {
				A[i]++;
			}
		}
		node = node->adr;
	}
	for (int i = 0; i < 10; i++) {
		if (A[i] != 0) {
			n++;
			cout << "| " << setw(5) << left << i << " | " << setw(17) << left << A[i] << " |" <<endl;
			cout << "-----------------------------" << endl;
		}
	}
	cout << "\n��� ������ ����� N ���� ����������� " << n << " ����� ����.\n";
}