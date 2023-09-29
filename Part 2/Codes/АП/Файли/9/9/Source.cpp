//� �������� ��������� ���� f � �������� ������ �������� ���������� ����������
//���������� �� ���������� ��������.
#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;


int size_file(const char*); //�������  ��� ���������� ��������� �����

int main()
{
    SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����

    const char* file = "f.txt"; //������ � ������ �����
    int size;                   //������� �������� � ����
    int n;                      //����� ��� ������� ��������� �����
    int max, min;               //��������� �� ��������� ��������
    //int max_i, min_i;           //���������� ���������� �� ���������� ��������
    int i = 0;                  //��������
    int k = 1;                  //����������
    ifstream fin(file); //�������� ����� f.txt
    if (!fin.is_open()) //�������� �� �������� ����
    {
        cout << "������� ���� f.txt �� ��������!";
        return 0;
    }
    
    size = size_file(file); //������� �������� � ����

    fin >> n; //���������� �������� � �����
    max = min = n;

    while (!fin.eof()) //����� max i min
    {
        fin >> n;
        while (i < size)
        {
            if (n > max) {
                max = n;
            }
            if (n < min) {
                min = n;
            }
            i++;
            break;
        }
    }
   
    fin.close();    //�������� ������ ����� - ������
    fin.open(file); //�������� ����� f.txt
   
    while (!fin.eof()) //����� ���������
    {
        fin >> n;
        while (k <= size)
        {
            if (n == max) {
                cout << "\n��������� ������� � ���� << " << max << " >> ����� " << k << " �������\n";
            }
            if (n == min) {
                cout << "\n��������� ������� � ���� << " << min << " >> ����� " << k << " �������\n";
            }
            k++;
            break;

        }

    }
    fin.close(); //�������� ������ ����� - ������
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
    return n ? n : -1; //���������� ������� �������� � ���� ��� -1, ���� ���� �������
}
