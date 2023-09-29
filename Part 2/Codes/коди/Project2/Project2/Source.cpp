//Натуральне число N представити у вигляді стеку його цифр.Підрахувати
//скільки різних цифр використано для запису числа.

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
void DifferentNumbers(stack*, int, const char*); //визначення кількості різних цифр
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
	DifferentNumbers(top, k, "Для запису числа N використано:");
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
void DifferentNumbers(stack* node, int n, const char* msg)
{
	int A[10]{ 0 };

	cout << "\n-----------------------------\n";
	cout << "| Цифра | К-сть використань |\n";
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
	cout << "\nДля запису числа N було використано " << n << " різних цифр.\n";
}