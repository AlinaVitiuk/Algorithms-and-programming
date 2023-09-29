#pragma once

#include <iostream>

using namespace std;

struct stack
{
    int info; //інформаційна частина
    stack* adr = NULL;  //вказівник на наступний елемент стеку
};

//прототипи функцій створення елементу, підрахунку цифр, виводу та видалення стеку
void AddtoStack(stack*&, int);
void QuantityOfDigits(stack*);
void PrintStack(stack*);
void DestroyStack(stack*&);
