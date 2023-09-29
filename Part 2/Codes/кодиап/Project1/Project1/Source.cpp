//������ � ��������� ��� ����� ���䒺���� �����.����� ���
//������� ������ ����������� ������. ���� ����� �� �������� ���������
//������� ����� �������.����������� �� ������� ������ ������� ������� �� �����

#include <iostream>     // �������� � ��������� ���������� ����
#include <Windows.h>    // ���������� ����������� �����
#include<time.h>        //���������� ����, �� ������ ���� � ������� ��� ������ � ����� � �����.
using namespace std;

void Offset_line(double** a, int n, int m, int k) //������� ����� �������
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

void Print_mtrx(double** a, int n, int m) //���� ������� �� �����
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
    SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����
    int n, m, k, y = 1;
    
    cout << "~��������� ������i~\n";
    do
    {
        cout << "\n����i�� ������� ����i�:";
        cin >> n;
    } while (n <= 0);
    {
        cout << "\n����i�� ������� ������i�:";
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
        cout << "~������� �������� �������~\n";
        do{
            cout << "������ ���������� ������� �������� k:"; cin >> k;
        } while (k<=0);

        Offset_line(a, n, m, k);
        Print_mtrx(a, n, m);
        cout << "������ ��������� ������� ������?\n";
        cout << "��� - ������ ~1~\n";
        cout << "ͳ - ������ ~����-���� ������~\n";
        cin >> y;
    }
    for (int i = 0; i < n; i++)
    delete[] a;
    return 0;
}