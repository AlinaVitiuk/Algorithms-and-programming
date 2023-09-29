//3. Задано натуральне число N > 1000. Надрукувати всі цифри числа 2^N

#include <iostream>
#include <Windows.h>
using namespace std;

//оголошення структури - елементу списку
struct stack
{
    int info; 
    stack* adr = 0;
    stack* prev = 0;
};

//функції
void AddtoStack(stack*&, int);       //додавання вузла до стеку
void PrintStack(stack*);             //друк стеку
void DeleteStack(stack*&);           //знищення стеку
void Multiply(int, stack*&, stack*); //множення на 2 n-разів

int main()
{
    SetConsoleOutputCP(1251);     //зміна кодування для використання кирилиці при виводі

    int n;
    cout << "\tОбчислення 2^N\n";
    cout << "Введіть N: ";
    cin >> n;
    if (n < 0) //перевірка коректності введеного
    {
        n = -n;
    }

    stack* head = 0; //вузол, який зберігатиме наймолодший розряд
    stack* node = 0; //вузол, який зберігатиме поточний розряд
    int a = 2;
    node = new stack;
    node->info = a;
    head = node;
   
    for (int i = 2; i <= n; i++)
    { 
        Multiply(i, node, head);
    }
    cout << "2^" << n << " = ";
    PrintStack(node);
    DeleteStack(node);
    return 0;
}

//додавання вузла до стеку
void AddtoStack(stack*& node, int a) 
{
    stack* tmp = new stack;
    tmp->info = a;
    tmp->prev = node;
    node->adr = tmp;
    node = tmp;
}

//друк стеку
void PrintStack(stack* node) 
{
    while (node)
    {
        cout << node->info; 
        node = node->prev; 
    }
    cout << endl;
}

//знищення стеку
void DeleteStack(stack*& node)
{
    stack* next;
    while (node)
    {
        next = node->prev;
        delete node;
        node = next;
    }
}

//множення на 2 n - разів
void Multiply(int i, stack*& node, stack* head)
{
    int carry = 0;
    stack* cur = head;
    while (cur)  
    {
        int prod = (cur->info * 2) + carry;
        cur->info = prod % 10;
        carry = prod / 10;
        cur = cur->adr;
    }
    while (carry)
    {
        AddtoStack(node, carry % 10);
        carry = carry / 10;
    }
}