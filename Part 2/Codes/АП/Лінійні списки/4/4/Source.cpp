//˳����� ������, �������� � ����� ������������, ����������� � ������ ��'�������
//������ ��� ���������� ��������.

#include <iostream>
#include <Windows.h>
using namespace std;

struct list //�������� �����'����� ������
{
    int info;
    list* next = NULL;   //�������� �� ��������� ���o� 
    list* prev = NULL;   //�������� �� ��������� ���o�
};

void AddtoList(list*&, int); //��������� �����
void PrintList(list*);       //���� ������
void SearchRepeats(list*&, list*&);  //����� ���������
void DestroyList(list*&);            //��������� �����

int main()
{
    SetConsoleOutputCP(1251);   //������������ ��������� Windows-1251 ��� ��������� �����
    list* head = NULL; //������ ������� ������
    list* tail = NULL; //������� ������� ������
    list* node;
    node = new list;
    head = tail = node;
    int N = 0;  //������ �������� � ������
    int num = 0;//������� ������
    cout << "\n������ ������� �������� � ������: "; 
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        cout << "\n������ " << i << " ������� ������: "; cin >> num;
        AddtoList(tail, num);
    }
    cout << "\n----------------------------------------------\n";
    cout << "\n˳����� ������: ";
    PrintList(head);
    SearchRepeats(head, tail);
    cout << "\n˳����� ������ ��� ���������� ��������: ";
    PrintList(head);
    DestroyList(tail);
    return 0;
}

void AddtoList(list*& node, int a) //��������� ����� �� ������
{
    list* prt = new list;
    prt->info = a;
    prt->prev = node;
    node->next = prt;
    node = prt;
}

void PrintList(list* node) //���� ������
{
    node = node->next;
    while (node)
    {
        cout << node->info << ' '; 
        node = node->next; 
    }
    cout << endl;
}

void SearchRepeats(list*& node, list*& tail) //����� ���������
{
    list* node_a = node->next;
    list* node_b = NULL;
    while (node_a) {
        node_b = node_a->next;
        while (node_b) {
            if (node_a->info == node_b->info) {
                if (node_b->next != NULL) {
                    node_b->prev->next = node_b->next;
                    node_b->next->prev = node_b->prev;
                }
                else {
                    node_b->prev->next = node_b->next;
                }
            }
            node_b = node_b->next;
        }
        node_a = node_a->next;
    }
}

void DestroyList(list*& node) //��������� �����
{
    list* next;
    while (node)
    {
        next = node->prev;
        delete node;
        node = next;
    }
}
