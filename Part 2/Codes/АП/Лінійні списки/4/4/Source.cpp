//Лінійний список, елементи в якому повторюються, представити у вигляді зв'язаного
//списку без повторення елементів.

#include <iostream>
#include <Windows.h>
using namespace std;

struct list //струкура двозв'язний список
{
    int info;
    list* next = NULL;   //вказівник на наступний вузoл 
    list* prev = NULL;   //вказівник на попередній вузoл
};

void AddtoList(list*&, int); //додавання вузла
void PrintList(list*);       //друк списку
void SearchRepeats(list*&, list*&);  //пошук повторень
void DestroyList(list*&);            //звільнення пам’яті

int main()
{
    SetConsoleOutputCP(1251);   //встановлення кодування Windows-1251 для виведення даних
    list* head = NULL; //перший елемент списку
    list* tail = NULL; //останній елемент списку
    list* node;
    node = new list;
    head = tail = node;
    int N = 0;  //кількісь елементів у списку
    int num = 0;//елемент списку
    cout << "\nВведіть кількість елементів у списку: "; 
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        cout << "\nВведіть " << i << " елемент списку: "; cin >> num;
        AddtoList(tail, num);
    }
    cout << "\n----------------------------------------------\n";
    cout << "\nЛінійний список: ";
    PrintList(head);
    SearchRepeats(head, tail);
    cout << "\nЛінійний список без повторення елементів: ";
    PrintList(head);
    DestroyList(tail);
    return 0;
}

void AddtoList(list*& node, int a) //додавання вузлів до списку
{
    list* prt = new list;
    prt->info = a;
    prt->prev = node;
    node->next = prt;
    node = prt;
}

void PrintList(list* node) //друк списку
{
    node = node->next;
    while (node)
    {
        cout << node->info << ' '; 
        node = node->next; 
    }
    cout << endl;
}

void SearchRepeats(list*& node, list*& tail) //пошук повторень
{
    list* node_a = node->next;
    list* node_b = NULL;
    while (node_a) {
        node_b = node_a->next;
        while (node_b) {
            if (node_a->info == node_b->info) {
                if (node_b->next != NULL) {
                    node_b->prev->next = node_b->next;
                    node_b->next->prev = node_b->prev;
                }
                else {
                    node_b->prev->next = node_b->next;
                }
            }
            node_b = node_b->next;
        }
        node_a = node_a->next;
    }
}

void DestroyList(list*& node) //звільнення пам’яті
{
    list* next;
    while (node)
    {
        next = node->prev;
        delete node;
        node = next;
    }
}
