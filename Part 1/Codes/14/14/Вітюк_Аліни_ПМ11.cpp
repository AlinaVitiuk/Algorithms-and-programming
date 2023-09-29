#include<iostream>
#include<cstdlib>
#include<ctime>
const int size1 = 10;
using namespace std;
void creat_mtr(int[][size1], int);
void print_mtr(int[][size1], int);
void sub_mtr(int[][size1], int, int[][size1], int[][size1]);
void mult_mtr(int[][size1], int, int[][size1], int[][size1]);
void mult1_mtr(int[][size1], int, int[][size1], int[][size1]);
int main()
{
    int n, mtrA[size1][size1] = { 0 };
    do
    {
        cout << "Size of matrix n = ";
        cin >> n;
    } while (n <= 0 || n > size1);
    srand(unsigned(time(0)));
    creat_mtr(mtrA, n);
    cout << "\nFirst matrix A:\n";
    print_mtr(mtrA, n);
    int mtrB[size1][size1] = { 0 };
    creat_mtr(mtrB, n);
    cout << "\nSecond matrix B:\n";
    print_mtr(mtrB, n);
    int mtrC[size1][size1] = { 0 };
    mult_mtr(mtrA, n, mtrB, mtrC);
    cout << "\nC=A*B\n";
    print_mtr(mtrC, n);
    int mtrQ[size1][size1] = { 0 };
    mult1_mtr(mtrA, n, mtrB, mtrQ);
    cout << "\nQ=B*A\n";
    print_mtr(mtrQ, n);
    int mtrH[size1][size1] = { 0 };
    sub_mtr(mtrC, n, mtrQ, mtrH);
    cout << "\nH=C-Q\n";
    print_mtr(mtrH, n);
    cout << "\nEnd\n";
    return 0;
}
void creat_mtr(int a[][size1], int n) //Створення матриці, яка запевнена довільними числами
{
    int b(100), c(10);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % (b - c) - c;
}
void print_mtr(int a[][size1], int n) //Вивід, створеної раніше, матриці
{
    for (int i = 0; i < n; cout << endl, i++)
        for (int j = 0; j < n; cout.width(7), cout << a[i][j++]);
}
void sub_mtr(int c[][size1], int n, int q[][size1], int h[][size1]) //Віднімання матриць AB-DB
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            h[i][j] = c[i][j] - q[i][j];
}
void mult_mtr(int a[][size1], int n, int b[][size1], int c[][size1]) // Множення AB
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int d = 0;
            for (int k = 0; k < n; k++)
                d += a[i][k] * b[k][j];
            c[i][j] = d;
        }
}
void mult1_mtr(int a[][size1], int n, int b[][size1], int q[][size1]) //Множення BA
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int d = 0;
            for (int k = 0; k < n; k++)
                d += b[i][k] * a[k][j];
            q[i][j] = d;
        }
}