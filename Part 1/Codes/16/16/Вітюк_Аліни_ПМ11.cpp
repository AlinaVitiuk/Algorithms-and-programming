#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>
using namespace std;
int main()
{
    int m, n;
    const int K = 10;
//Задання розміності матриці 
    do
    {
        cout << "Vvedit kilkist ryadkiv matrytsi: ";
        cin >> m;
    } while (m > K or m <= 0);
    do
    {
        cout << "Vvedit kilkist stovptsiv matrytsi: ";
        cin >> n;
    } while (n > K or n <= 0);
    int a[K][K];
    srand(time(0));
//Створення матриці, яка заповнено довілними елементами
    cout << "Zhenerovana matrytsya" << endl;
    for (int i = 0; i < m; cout << endl, i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 5;
            cout.width(4);
            cout << a[i][j];
        }
    }
    int k = 0, flag = 0;
    for (k; k < m; k++)
    {
//Пошук min елемента в рядку
        int min = a[k][0], p = 1, minp = 0;
        for (p; p < n; )
        {
            if (a[k][p] < min)
            {
                min = a[k][p];
                minp = p;
                p++;
            }
            else
            {
                p++;
            }
        }
//Пошук max елемента в стовпцях
        int f = 1, max = a[k][minp];
        for (; f < m; )
        {
            if (max > a[f][minp])
            {
                f++;
                if (max == a[k][minp])
                {
                    cout << "Sidlovoyi tochka: a[" << k + 1 << "][" << minp + 1 << "]" << endl; //Формування сідлової точки
                    flag = 1;
                }
            }
            else
            {
                f++;
                break;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Sidlovoyi tochky nemaye" << endl; //Вивід інформації, що сідлової точки не існує
    }
}