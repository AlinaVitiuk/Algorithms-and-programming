//Ввести з клавіатури три цілих невід’ємних числа.Перші два
//задають розміри двовимірного масиву. Третє вказує на величину циклічного
//зміщення рядків матриці.Згенеровану та циклічно зміщену матриці вивести на екран

#include <iostream>     // бібліотека і відповідний заголовний файл
#include <Windows.h>    // підключення заголовного файлу
#include<time.h>        //заголовний файл, що містить типи і функції для роботи з датою й часом.
using namespace std;

void Offset_line(double** a, int n, int m, int k) //зміщення рядків матриці
{
    double temp;
    for (int p = 1; p <= k; p++)
    {
        for (int j = 0; j < m; j++)
        {
            temp = a[n - 1][j];
            for (int i = n - 1; i > 0; i--)
                a[i][j] = a[i - 1][j];
            a[0][j] = temp;
        }
    }
}

void Print_mtrx(double** a, int n, int m) //вивід матриці на екран
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        { 
            cout.width(5);
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    SetConsoleOutputCP(1251); //Встановлення кодування Windows-1251 для виведення даних
    int n, m, k, y = 1;
    
    cout << "~Створення матрицi~\n";
    do
    {
        cout << "\nВведiть кількість рядкiв:";
        cin >> n;
    } while (n <= 0);
    {
        cout << "\nВведiть кількість стовпцiв:";
        cin >> m;
    } while (m <= 0);
    double** a = new double* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new double[m];
    }
    int c = 10, d = 100;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = rand() % (d - c);
                cout.width(5);
                cout << a[i][j];
            }
            cout << endl;
        }
    char ch;
    while (y == 1)
    {
        cout << "~Зміщення стовпців матриці~\n";
        do{
            cout << "Введіть коефіцієнт зміщення стовпців k:"; cin >> k;
        } while (k<=0);

        Offset_line(a, n, m, k);
        Print_mtrx(a, n, m);
        cout << "Хочете повторити зміщення стовпів?\n";
        cout << "Так - введіть ~1~\n";
        cout << "Ні - введіть ~будь-який символ~\n";
        cin >> y;
    }
    for (int i = 0; i < n; i++)
    delete[] a;
    return 0;
}