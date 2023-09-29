#include<iostream>
using namespace std;
int main()
{
    int a[50], n, i, j, temp;
    do
    {
        cout << "Vvedit kilkist n = "; cin >> n; //задання розмірності масиву
    } while (n < 1);
    double x;
    for (int i = 0; i < n; i++)
    {
        cout << "\nVvedit element x = "; cin >> a[i]; //ввід елементів масиву
    }
//Процес сортування масиву по зростанню
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < (n - i); j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    }
//Вивід результату
    cout << "Result:";
    for (i = 0; i < n; i++)
        cout << " " << a[i];
    return 0;
}