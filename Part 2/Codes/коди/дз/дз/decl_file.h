//decl_file.h - заголовковий файл

#pragma once
#include<iostream>
#include<string.h>
#include <Windows.h>
#pragma warning(disable:4996) /* директива для уникнення неістотних повідомлень */
using namespace std;

//структура дробів
struct Fraction
{
	int numerator, denominator; /* чисельник і значенник */
	void EnterFraction(); /* введення дробу */
	void PrintFraction(); /* друк дробу */
};

//функції
int EnterNumber(); /* введення числа*/
void EnterArrayFraction(Fraction*, int); /* введення масиву */
void PrintArrayFraction(Fraction*, int); /* друк масиву */
void SearchArrayFraction(Fraction*, int); /* пошук дробів чисельники яких є непарними числами */