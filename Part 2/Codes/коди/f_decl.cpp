#include "decl_file.h"


void AddtoStack(stack*& node, int a) //додавання нового елементу
{
    stack* prev = node;
    node = new stack;
    node->info = a;
    node->adr = prev;
}
void QuantityOfDigits(stack* node) {//функція підрахування кількості кожної цифри
    int array[10]{ 0 };
    //масив з кількістю цифр
    //i - цифра
    //array[i] - кількість повторень цифри i
    while (node) {//поки елемент стеку існує
        for (int i = 0; i < 10; i++) {//цикл перевірки цифр
            if (node->info == i) {
                array[i]++;
            }
        }
        node = node->adr;//перехід до наступного елементу
    }
    for (int i = 0; i < 10; i++) {//вивід кількості цифр
        if (array[i] != 0) {
            cout << "\n" << i << " - " << array[i] << " times";
        }
    }
}
void PrintStack(stack* node) //вивід стеку
{
    while (node) {
        cout << node->info << "  ";
        node = node->adr;
    }
    cout << endl;
}
void DestroyStack(stack*& node) //видалення стеку
{
    stack* next;
    while (node) {
        next = node->adr;
        delete node;
        node = next;
    }
}