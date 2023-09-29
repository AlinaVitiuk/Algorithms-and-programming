//Написати функцію сортування зв’язаного списку методом вставки
#include <iostream>
#include <Windows.h>
using namespace std;

struct list {
	int info;
	list* prev, * next;
};

list* AddToList(list*, list*); //додавання нового елементу до списку
void PrintList(list*, list*);  //друк списку
void SortList(list*&, list*&); //сортування
void DestroyList(list*&, list*&); //звільнення пам’яті

int main()
{
	SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних
	int n, number; //n - кількість елементів у списку
	               //number - елемент списку
	list* head = NULL; //перший елемент списку
	list* tail = NULL; //останній елемент списку
	head->next = tail;
	tail->prev = head;
	cout << "\nВведіть бажану кількість елементів зв'язаного списку: ";
	cin >> n;
	list* last = head;
	for (int i = 1; i <= n; i++) {
		cout << "\nВведіть " << i << " елемент списку: "; 
		cin >> number;
		list* node = new list;
		node->info = number;
		last = AddToList(last, node);
	}
	cout << "\nВаш зв’язаний список: ";
	PrintList(head, tail);
	SortList(head, tail);
	cout << "\nВідсортований список: ";
	PrintList(head, tail);
	DestroyList(head, tail);

}

list* AddToList(list* last, list* node) {
	//функція вставляє елемент node в список після елементу last та перевстановлює зв'язки повертає адресу вставленого елементу
	if (last && node)
	{
		node->prev = last;
		node->next = last->next;
		last->next = node;
		node->next->prev = node;
		return node;
	}
	else
		return NULL;
}

void PrintList(list* head, list* tail)
{
	list* node = head->next;
	while (node != tail)
	{
		cout << node->info << ' ';
		node = node->next;
	}
	cout << endl;
}

void SortList(list*& head, list*& tail) {
	list* left, * right = head->next;
	list* node = new list;
	bool flag = false;
	while (right != tail) {
		node->info = right->info; //поточний вузол
		left = right->prev;
		while (left && node->info < left->info) {//поточний вузол порівнюється з усіма, що є ліворуч від нього
			(left->next)->info = left->info;
			if (left->prev) left = left->prev; // якщо left->prev існує, то перехід на попередній елемент
			else { // якщо left->prev не існує, то цикл зупиняється і піднімається прапорець
				flag = true;
				break;
			}
			//усі вузли, що є більшими зсуваються праворуч
		}

		//якщо знайшовся елемент менший за поточний, то цей поточний елемент стає на своє місце
		if (!flag) (left->next)->info = node->info; // якщо left->prev існує, то змінюємо значення наступного вузла
		else { // якщо left->prev не існує, то найперший елемент буде left, а не left->next
			left->info = node->info;
			flag = false;
		}
		right = right->next;
	}
}

void DestroyList(list*& head, list*& tail) {
	list* next = NULL;
	while (next != tail) {
		next = head->next;
		delete head;
		head = next;
	}
	delete tail;
}