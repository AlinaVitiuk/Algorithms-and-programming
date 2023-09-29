#include "decl_file.h"

int main()
{
    int n;
    do {
        cout << "\nEnter 0 if you want to exit";
        cout << "\nEnter a natural number = ";
        cin >> n;
        int exit = n;//змінна, що потрібна для виходу, оскільки n в подальшому стане 0
        if (exit == 0) return 0; //перевірка на вихід з програми
        n = (n < 0) ? -n : n; //перевірка чи число не є від'ємним
        stack* top = NULL;//порожній елемент
        do {
            AddtoStack(top, n % 10);
            //створення нового елементу стеку та запис туди остачі від ділення на 10
            n /= 10;//зменшення числа, аби знищити остачу
        } while (n != 0); //алгоритм розділення числа на цифри
        cout << "\nSeparated digits " << " = " << "\t";
        PrintStack(top);
        cout << "\nDigits are used: ";
        QuantityOfDigits(top);
        DestroyStack(top);
    } while (exit != 0);//цикл для не виходу з програми
    return 0;
}