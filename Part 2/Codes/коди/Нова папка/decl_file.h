#pragma once
#include<iostream>
#include<cstring>
#include<Windows.h>

#pragma warning(disable:4996)

using namespace std;

struct Fraction {//структура дріб
	int numerator, denominator;
	void EnterFrac();
	void PrintFrac();
};
//прототипи функцій
int EnterNumber();
int menu();
void EnterArrayFrac(Fraction*, int);
void PrintArrayFrac(Fraction*, int);
void FindOddNumerator(Fraction*, int);