//3. ������ ���������� ����� N > 1000. ����������� �� ����� ����� 2^N

#include <iostream>
#include <Windows.h>
using namespace std;

//���������� ��������� - �������� ������
struct stack
{
    int info; 
    stack* adr = 0;
    stack* prev = 0;
};

//�������
void AddtoStack(stack*&, int);       //��������� ����� �� �����
void PrintStack(stack*);             //���� �����
void DeleteStack(stack*&);           //�������� �����
void Multiply(int, stack*&, stack*); //�������� �� 2 n-����

int main()
{
    SetConsoleOutputCP(1251);     //���� ��������� ��� ������������ �������� ��� �����

    int n;
    cout << "\t���������� 2^N\n";
    cout << "������ N: ";
    cin >> n;
    if (n < 0) //�������� ���������� ���������
    {
        n = -n;
    }

    stack* head = 0; //�����, ���� ���������� ����������� ������
    stack* node = 0; //�����, ���� ���������� �������� ������
    int a = 2;
    node = new stack;
    node->info = a;
    head = node;
   
    for (int i = 2; i <= n; i++)
    { 
        Multiply(i, node, head);
    }
    cout << "2^" << n << " = ";
    PrintStack(node);
    DeleteStack(node);
    return 0;
}

//��������� ����� �� �����
void AddtoStack(stack*& node, int a) 
{
    stack* tmp = new stack;
    tmp->info = a;
    tmp->prev = node;
    node->adr = tmp;
    node = tmp;
}

//���� �����
void PrintStack(stack* node) 
{
    while (node)
    {
        cout << node->info; 
        node = node->prev; 
    }
    cout << endl;
}

//�������� �����
void DeleteStack(stack*& node)
{
    stack* next;
    while (node)
    {
        next = node->prev;
        delete node;
        node = next;
    }
}

//�������� �� 2 n - ����
void Multiply(int i, stack*& node, stack* head)
{
    int carry = 0;
    stack* cur = head;
    while (cur)  
    {
        int prod = (cur->info * 2) + carry;
        cur->info = prod % 10;
        carry = prod / 10;
        cur = cur->adr;
    }
    while (carry)
    {
        AddtoStack(node, carry % 10);
        carry = carry / 10;
    }
}