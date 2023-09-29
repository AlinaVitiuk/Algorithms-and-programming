#include <iostream>

using namespace std;

struct list {
	int info;
	list* prev, * next;
};

list* AddToList(list*, list*);
void PrintList(list*, list*);
void SortList(list*&, list*&);
void DestroyList(list*&, list*&);

int main()
{
	int n, number;
	list* head = new list;
	list* tail = new list;
	head->next = tail;
	tail->prev = head;
	cout << "\nEnter the number of elements = ";
	cin >> n;
	list* last = head;
	for (int i = 0; i < n; i++) {
		cout << "\nEnter the number = ";
		cin >> number;
		list* node = new list;
		node->info = number;
		last = AddToList(last, node);
	}
	cout << "\nYour list: ";
	PrintList(head, tail);
	SortList(head, tail);
	cout << "\nSorted list: ";
	PrintList(head, tail);
	DestroyList(head, tail);

}

list* AddToList(list* last, list* node) {
	//������� �������� ������� node � ������, ���� �������� last �� �������������� ������
	//������� ������ ����������� ��������
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
	//���������� ������������ ������ �� ������� �������������
	list* last = tail;
	tail->next = head;
	head->prev = tail;
	while (head->next != tail) {//���� � ������ � ��������
		list* min = head->next, * node = head->next;//����� ���������� �������� � ������������ �� ���������
		while (node != tail)
		{
			if (node->info < min->info)
				min = node;
			node = node->next;
		}
		//������ ������, ��������� �� ��������� ������� �������� ���� �� ������, � ����� ����������
		min->next->prev = min->prev;
		min->prev->next = min->next;

		last = AddToList(last, min);//��������� ������� ������ �� ������� ������ ������
	}
	swap(head, tail);//���� ������ �� ������ ������
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