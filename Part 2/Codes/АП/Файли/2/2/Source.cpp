//��� ������� ������������� �������� ����� f �� g �������� �������� ������ ���
//���� ����� � ������������� ���� ff.

#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int size_file(const char*);  //������������ ������� �������� � ����
int from_file_to_array(const char*, int*&, int&); //����� ����� � ����� � �����

int main()
{
    SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����

    const char* data1 = "f.txt", * data2 = "g.txt", * data3 = "ff.txt"; //������ � ������� �����
    int* arr1 = 0, * arr2 = 0, * arr3 = 0; //arr1, arr2, arr3 - ����� ������
    int size1, size2, size3; //���� ��� ���������� ������� �������� � ������ (��������� ������)
    int i = 0, j = 0, k = 0; //���������

    //������������ ������� �������� � ������
    size1 = size_file(data1);
    size2 = size_file(data2);
    size3 = size1 + size2;

    //�������� ���'�� �� ��������� �����
    arr3 = new int[size3];

    //����� ����� � ����� � ������
    from_file_to_array(data1, arr1, size1);
    from_file_to_array(data2, arr2, size2);
    
    //������ ������
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        arr3[k++] = arr1[i++];
    }
    while (j < size2) {
        arr3[k++] = arr2[j++];
    }

    ofstream fout(data3); //��������� ������ ����� ff.txt
    for (int k = 0; k < size3; k++)
    {
        fout << arr3[k] << " "; //����� ����� � ����
    }
    if (size3 > 0) {
        cout << "\n���� ff.txt ��������� ������� �������� � ����� f.txt i g.txt\n";
    }
    else {
        cout << "\n������� ��� ��������� ����� ff.txt ������� �������� � ����� f.txt i g.txt\n";
    }
    delete[] arr1, arr2, arr3; //��������� ���'��
    fout.close(); //�������� �����
}

int size_file(const char* fn) {
    int n = 0; // n - ������� �������� � ����
    int a;     // a - ������������ ����� ��� ��������� ��������� ������, ��������� � �����
    ifstream file;
    file.open(fn);
    while (!file.eof()) //���� �� ��������� ���� �����
    {
        file >> a;
        n++;
    }
    file.close();      //�������� �����
    return n ? n : -1; //���������� ������� �������� � ���� ��� -1, ���� ���� �������
}

int from_file_to_array(const char* fn, int*& a, int& n) //����� ����� � ����� � �����
{
    ifstream file;
    file.open(fn);
    n = size_file(fn); //������������ ������� �������� � ����
    a = new int[n];    //�������� ���'�� �� ��������� �����
    for (int i = 0; i < n;)
    {
        file >> a[i++]; //�������� ��� ����� � ����� � �����
    }
    if (!file.is_open()) {
        printf("\n ���� %s �� ��������\n", fn);
    }
    file.close(); //�������� �����
    return 1;     //���������� �������� "����"
}