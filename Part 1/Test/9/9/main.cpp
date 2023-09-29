#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    int m, n;
    const int K = 10;
    do
    {
        cout << "Введіть кількість рядків матриці: ";
        cin >> m;
    } while (m > K or m <= 0);
    do
    {
        cout << "Введіть кількість стовпців матриці: ";
        cin >> n;
    } while (n > K or n <= 0);
    int a[K][K];
    srand(time(0));
    cout << "Згенерована матриця" << endl;
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
        int f = 1, max = a[k][minp];
        for (; f < m; )
        {
            if (max > a[f][minp])
            {
                f++;
                if (max == a[k][minp])
                {
                    cout << "Сідлова точка: a[" << k + 1 << "][" << minp + 1 << "]" << endl;
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
        cout << "Сідлової точки немає" << endl;
    }
}