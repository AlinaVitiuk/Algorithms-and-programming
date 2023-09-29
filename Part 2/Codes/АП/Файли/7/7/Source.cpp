//��� ����������, ����������� ����� ����� � ����
//f, ��������� �������� ����������� ���������

#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;

int size_file(const char*); //������������ ������� �������� � ����
double integral(double, int, double*); //������������

int main()
{
    SetConsoleOutputCP(1251);    //������������ ��������� Windows-1251 ��� ��������� �����
    const char* file = "fn.txt"; //������ � ������� �����
    double* arr = 0;             //�����, � ���� ���� ������� ������� �����
    int size;                    //����� ������
    double n; int i = 0;         //n - ������ �����������, i - ��������
    double P = 0;                //P - �������� ����������� ���������

    size = size_file(file);     //������������ ������� �������� � ����
    arr = new double[size];     //�������� ���'�� �� ��������� �����

    ifstream fin(file);      //�������� ����� f.txt

    if (!fin.is_open()) {    //���� ������� ���� �� ������� �������
        cout << "������� ���� �� ��������!";
        return 0;
    }

    //����� ����� � ����������� � �����
    while (!fin.eof())
    {
        fin >> n;
        while (i < size)
        {
            arr[i] = n;
            i++;
            break;
        }
    }

    P = integral(5.76, size, arr) - integral(2.34, size, arr);
    cout << "�������� �� ������ [2.34; 5.76] = " << P << endl; //���� ���������� �� �����

    delete[] arr;
    return 0;
}

int size_file(const char* fn) { //������������ ������� �������� � ����
    int size = 0; // n - ������� �������� � ����
    double a;        //a - ������������ ����� ��� ��������� ��������� ������, ��������� � �����
    ifstream file;
    file.open(fn);
    while (!file.eof()) //���� �� ��������� ���� �����
    {
        file >> a;
        size++;
    }
    file.close(); //�������� �����
    return size;  //���������� ������� �������� � ���� ��� -1, ���� ���� �������
}

double integral(double x, int size, double* arr) //������������
{
    double p = 0; //�������� ���������� � ������ �����
    for (int j = size, i = 0; j > 0, i < size; j--, i++)
    {
        p += arr[i] / j * pow(x, j);
    }
    return p;
}