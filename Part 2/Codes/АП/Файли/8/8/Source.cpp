// ��� ���������� P(x), ����������� ����� ����� � ����, ��������� �������� �������� P'(2.34), P'(7.2), P'(5.3)
#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;

int size_file(const char*);           //�������  ��� ���������� ��������� �����
double Derivative(double, int, int*); //������� ��� ������ �������
int main()
{
    SetConsoleOutputCP(1251);   //������������ ��������� Windows-1251 ��� ��������� �����
    const char* file = "fn.txt"; //������ � ������� �����
    int* arr = 0;            //�����, � ���� ���� ������� ������� �����
    int size;                   //����� ������
    double n; int i = 0;        //n - ������ �����������, i - ��������
    double P = 0;               //P - �������� ����������� ���������

    size = size_file(file);     //������������ ������� �������� � ����
    arr = new int[size];     //�������� ���'�� �� ��������� �����

    ifstream fin(file);      //�������� ����� f.txt

    if (!fin.is_open()) {    //���� ������� ���� �� ������� �������
        cout << "������� ���� �� ��������!";
        return 0;
    }

    while (!fin.eof()) //���������� ������ ������������� � �����
    {
        fin >> n;
        while (i < size)
        {
            arr[i] = n;
            i++;
            
            break;
        }

    }

    //�������� �������� ���� � ������� � �������� ������ � ��� ������
    cout << "\nP'(2.34) = " << Derivative(2.34, size, arr) << endl;
    cout << "\nP'(7.2)  = " << Derivative(7.2, size, arr) << endl;
    cout << "\nP'(5.3)  = " << Derivative(5.3, size, arr) << endl;
    delete[] arr;
    return 0;
}

int size_file(const char* fn) {
    int n = 0; // n - ������� �������� � ����
    int a; //a - ������������ ����� ��� ��������� ��������� ������, ��������� � �����
    ifstream file;
    file.open(fn);
    while (!file.eof()) //���� �� ��������� ���� �����
    {
        file >> a;
        n++;
    }
    file.close(); //�������� �����
    return n; //���������� ������� �������� � ���� ��� -1, ���� ���� �������
}

double Derivative(double x, int size, int* arr)
{
    double der = 0;
    int size1 = size - 2;

    for (int j = size1, i = 0; j > 0, i < size; j--, i++)
    {

        der += arr[i] * (j + 1) * pow(x, j);


    }
    return der;
}
