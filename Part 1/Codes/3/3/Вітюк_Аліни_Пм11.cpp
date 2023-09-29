#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    const int k = 100; // Розмірність масиву (k<=100)
    int a[k], s = 0;
    cout << "Zgenerovanyi massuv = ";
    for (int i = 0; i <= k; i++)
    {
        a[i] = rand() % 41 - 20; //Формування рандомного масиву
        cout << a[i] <<" ";
        if (a[i] > 0)
        {
            s++;
        }
    }
    cout << "\nKilkist dodatnich elementiv u nabori = " << s;
    return 0;
}