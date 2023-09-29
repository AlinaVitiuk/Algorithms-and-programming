//�������� ������� ���������� ��������� ������ ������� �������
#include <iostream>
#include <Windows.h>
using namespace std;

struct list {
	int info;
	list* prev, * next;
};

list* AddToList(list*, list*); //��������� ������ �������� �� ������
void PrintList(list*, list*);  //���� ������
void SortList(list*&, list*&); //����������
void DestroyList(list*&, list*&); //��������� �����

int main()
{
	SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����
	int n, number; //n - ������� �������� � ������
	               //number - ������� ������
	list* head = NULL; //������ ������� ������
	list* tail = NULL; //������� ������� ������
	head->next = tail;
	tail->prev = head;
	cout << "\n������ ������ ������� �������� ��'������� ������: ";
	cin >> n;
	list* last = head;
	for (int i = 1; i <= n; i++) {
		cout << "\n������ " << i << " ������� ������: "; 
		cin >> number;
		list* node = new list;
		node->info = number;
		last = AddToList(last, node);
	}
	cout << "\n��� �������� ������: ";
	PrintList(head, tail);
	SortList(head, tail);
	cout << "\n³����������� ������: ";
	PrintList(head, tail);
	DestroyList(head, tail);

}

list* AddToList(list* last, list* node) {
	//������� �������� ������� node � ������ ���� �������� last �� �������������� ��'���� ������� ������ ����������� ��������
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
		node->info = right->info; //�������� �����
		left = right->prev;
		while (left && node->info < left->info) {//�������� ����� ����������� � ����, �� � ������ �� �����
			(left->next)->info = left->info;
			if (left->prev) left = left->prev; // ���� left->prev ����, �� ������� �� ��������� �������
			else { // ���� left->prev �� ����, �� ���� ����������� � ��������� ���������
				flag = true;
				break;
			}
			//�� �����, �� � ������� ���������� ��������
		}

		//���� ��������� ������� ������ �� ��������, �� ��� �������� ������� ��� �� ��� ����
		if (!flag) (left->next)->info = node->info; // ���� left->prev ����, �� ������� �������� ���������� �����
		else { // ���� left->prev �� ����, �� ��������� ������� ���� left, � �� left->next
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