#pragma once
#include<iostream>
#include<cstring>
#include<Windows.h>

#pragma warning(disable:4996)

using namespace std;

struct Fraction {//��������� ���
	int numerator, denominator;
	void EnterFrac();
	void PrintFrac();
};
//��������� �������
int EnterNumber();
int menu();
void EnterArrayFrac(Fraction*, int);
void PrintArrayFrac(Fraction*, int);
void FindOddNumerator(Fraction*, int);