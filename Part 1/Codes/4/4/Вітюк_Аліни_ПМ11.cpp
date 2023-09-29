#include<iostream>
#include<math.h>
using namespace std;
const int size1 = 20;
int main()

{
//Генерування масиву дійсних чисел;
    double a[size1];
    int b = 10;
    cout << "Zgenerovanyi masyv:\n";
    cout.fixed;
    for (int i = 0; i < size1; i++)
    {
        a[i] = rand() % 41 - 20;
        cout.width(8);
        cout.precision(3);
        cout << a[i];
    }
//Знаходження max i min та їх розташукання у масиві;
    int i_max, i_min;
    i_max = i_min = 0;
    for (int i = 1; i < size1; i++)
        if (a[i] > a[i_max])
            i_max = i;
        else if (a[i] < a[i_min])
            i_min = i;
//Зміна розташування max i min за допомогою додаткогої змінної;
    double d = a[i_min];
    a[i_min] = a[0];
    a[0] = d;
    double c = a[i_max];
    a[i_max] = a[size1 - 1];
    a[size1 - 1] = c;
 //Вивід масиву після обміну;
    cout << "\nMasyv pislia obminu:\n";
    cout.fixed;
    for (int i = 0; i < size1; i++)
    {
        cout.width(8);
        cout.precision(3);
        cout << a[i];
    }
    return 0;
}