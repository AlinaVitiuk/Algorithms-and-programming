#include <iostream>
#include <Windows.h>
using namespace std;

typedef long long dane; //������������ ��������� dane ��� ���� long long

struct stack
{
    int info;           //������������ �������
    stack* adr = NULL;  //�������� �� ��������� �������
};

void AddtoStack(stack*&, dane);             //��������� ������ �������� �� �����
void PrintStack(stack*, const char*);       //���� �����
void DestroyStack(stack*&);                 //��������� �����

int main()
{
    SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����
    stack* top = NULL;
    dane n = 0;
    
    cout << "������ ���������� ����� N: ";
    cin >> n;
    if (n < 0)
        n = -n;
    int rd = 10;
    do {
        int rm = n % rd; //������ �� ������
        if (rm == 0 || rm == 1) {
            AddtoStack(top, !rm);
        }
        else {
            AddtoStack(top, rm);
        }
    } while (n /= rd);
    cout << "\n";
    PrintStack(top, "���� ���� ����� N, � ����� 0 ������ �� 1 � �������: ");
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