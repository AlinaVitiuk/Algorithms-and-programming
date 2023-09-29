#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
typedef int dani;
const int size1 = 10, size2 = 15;
typedef dani matrix[size1][size2];
int main()
{
    matrix a;
    int m, n, value(10);
//Ввід розмірності матриці
    do
    {
        cout << "\nVvedit m = "; cin >> m;
    } while (m < 0 || m > size1);
    do
    {
        cout << "\nVvedit n = "; cin >> n;
    } while (n < 0 || n > size2);
    srand(time(0));
//Генерування матриці
    cout << "\nZhenerovana matrucia:\n";
    for (int i = 0; i < m; cout << "\n", i++)
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % value;
            cout.width(4); cout << a[i][j];
        }
    int flag = 1, k = n;
    while (flag && k > 1)
//Сортування елементів матриці
    {
        flag = 0;
        k--;
        for (int j = 0; j < k; j++)
        {
            if (a[0][j] > a[0][j + 1])
            {
                for (int i = 0; i < n; i++)
                {
                    dani b = a[i][j];
                    a[i][j] = a[i][j + 1];
                    a[i][j + 1] = b;
                    flag = 1;
                }
            }
        }
    }
//Вивід відсортованої матриці
    cout << "\nVidsortovana matrycia:\n";
    for (int i = 0; i < m; cout << "\n", i++)
        for (int j = 0; j < n; j++)
        {
            cout.width(4); cout << a[i][j];
        }
    return 0;
}