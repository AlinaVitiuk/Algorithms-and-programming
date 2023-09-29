#include <iostream>
#include <Windows.h>
using namespace std;

typedef long long dane; //встановлення псевдоніму dane для типу long long

struct stack
{
    int info;           //інформаційна частина
    stack* adr = NULL;  //вказівник на наступний елемент
};

void AddtoStack(stack*&, dane);             //додавання нового елементу до стеку
void PrintStack(stack*, const char*);       //друк стеку
void DestroyStack(stack*&);                 //звільнення пам’яті

int main()
{
    SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних
    stack* top = NULL;
    dane n = 0;
    
    cout << "Введіть натуральне число N: ";
    cin >> n;
    if (n < 0)
        n = -n;
    int rd = 10;
    do {
        int rm = n % rd; //остача від ділення
        if (rm == 0 || rm == 1) {
            AddtoStack(top, !rm);
        }
        else {
            AddtoStack(top, rm);
        }
    } while (n /= rd);
    cout << "\n";
    PrintStack(top, "Стек цифр числа N, у якому 0 змінено на 1 і навпаки: ");
    return 0;
}

void AddtoStack(stack*& node, dane a) //додавання нового елементу до стеку
{
    stack* prev = node;
    node = new stack;
    node->info = a;
    node->adr = prev;

}
void PrintStack(stack* node, const char* msg) //друк стеку
{
    cout << msg << endl;
    while (node)
    {
        cout << node->info << ' ';
        node = node->adr;
    }
    cout << endl;
}
void DestroyStack(stack*& node) //звільнення пам’яті
{
    stack* next;
    while (node)
    {
        next = node->adr;
        delete node;
        node = next;
    }
}