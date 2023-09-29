//Задано натуральне число N.Створити стек з його цифр та підрахувати суму цифр у
//його представленні

#include<iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

typedef long long dane; //встановлення псевдоніму dane для типу long long

struct stack //оголошення  стеку
{
	dane info;
	stack* adr;
};

void AddtoStack(stack*&, dane);             //додавання нового елементу до стеку
void PrintStack(stack*, const char*);       //друк стеку
void DestroyStack(stack*&);                 //звільнення пам’яті
void SumDifferentNumbers(stack*, int);      //визначення суми різних цифр
int main()
{
	SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних
	stack* top = NULL;
	dane n = 0;
	int k = 0;
	cout << "Введіть натуральне число N: ";
	cin >> n;
	if (n < 0)
		n = -n;
	int rd = 10;
	do
		AddtoStack(top, n % rd);
	while (n /= rd);
	cout << "\n";
	PrintStack(top, "Стек цифр числа N: ");
	SumDifferentNumbers(top, k);
	DestroyStack(top);
	return 0;
}

void AddtoStack(stack*& node, dane a) //додавання нового елементу до стеку
{
	stack* prev = node;
	node = new stack;
	node->info = a;
	node->adr = prev;

}
void PrintStack(stack* node, const char* msg) //друк стеку
{
	cout << msg << endl;
	while (node)
	{
		cout << node->info << ' ';
		node = node->adr;
	}
	cout << endl;
}
void DestroyStack(stack*& node) //звільнення пам’яті
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
	cout << "Для запису числа N було використано наступні числа: ";
	for (int i = 0; i < 10; i++) {
		if (A[i] != 0) {
			n += i; //сума цифр
			cout << i << " ";
		}
	}
	cout << "\nСума цифр у представленні числа N = " << n << endl;
}