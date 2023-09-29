#include "decl_file.h"


void AddtoStack(stack*& node, int a) //��������� ������ ��������
{
    stack* prev = node;
    node = new stack;
    node->info = a;
    node->adr = prev;
}
void QuantityOfDigits(stack* node) {//������� ����������� ������� ����� �����
    int array[10]{ 0 };
    //����� � ������� ����
    //i - �����
    //array[i] - ������� ��������� ����� i
    while (node) {//���� ������� ����� ����
        for (int i = 0; i < 10; i++) {//���� �������� ����
            if (node->info == i) {
                array[i]++;
            }
        }
        node = node->adr;//������� �� ���������� ��������
    }
    for (int i = 0; i < 10; i++) {//���� ������� ����
        if (array[i] != 0) {
            cout << "\n" << i << " - " << array[i] << " times";
        }
    }
}
void PrintStack(stack* node) //���� �����
{
    while (node) {
        cout << node->info << "  ";
        node = node->adr;
    }
    cout << endl;
}
void DestroyStack(stack*& node) //��������� �����
{
    stack* next;
    while (node) {
        next = node->adr;
        delete node;
        node = next;
    }
}