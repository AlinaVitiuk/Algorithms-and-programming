#pragma once

#include <iostream>

using namespace std;

struct stack
{
    int info; //������������ �������
    stack* adr = NULL;  //�������� �� ��������� ������� �����
};

//��������� ������� ��������� ��������, ��������� ����, ������ �� ��������� �����
void AddtoStack(stack*&, int);
void QuantityOfDigits(stack*);
void PrintStack(stack*);
void DestroyStack(stack*&);
