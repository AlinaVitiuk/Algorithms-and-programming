//6. ��� ������� ��������������� �������� ����� f �� g �������� �������� ��������
//��� ���� ����� � ����� ���� ff.
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
    int* arr1 = 0, * arr2 = 0, * arr3 = 0; //a, b, c - ����� ������
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

    //������� ������
    while (i < size1 && j < size2)
    {
        for (j = 0; j < size2; j++)
        {
            for (i = 0; i < size1; i++)
            {
                if (arr2[j] == arr1[i])
                    arr3[k++] = arr2[j];
            }
        }
    }

    //c��������� ������ arr3
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (arr3[i] > arr3[j]) {
                int p = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = p;
            }
        }
    }
    ofstream fout(data3); //��������� ������ ����� ff.txt
    for (int i = 0; i < k; fout << arr3[i++] << " ") //����� ����� � ����
    
    if (size1 == 1 || size2 == 1)
    {
        cout << "\n��������, ���� �����, �� �������� ����� �����\n";
    }
    if (k > 0) {
        cout << "\n���� ff.txt ��������� ��������� �������� � ����� f.txt i g.txt\n";
    }
    else {
        cout << "\n������� ��� ��������� ����� ff.txt ��������� �������� � ����� f.txt i g.txt. �� �������� ������� �������� ��� ����� f.txt i g.txt\n";
    }
    delete[] arr1, arr2, arr3; //��������� ���'��
    fout.close(); //�������� �����
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

int from_file_to_array(const char* fn, int*& a, int& n) //����� ����� � ����� � �����
{
    ifstream file;
    file.open(fn);
    n = size_file(fn); //������������ ������� �������� � ����
    a = new int[n]; //�������� ���'�� �� ��������� �����
    for (int i = 0; i < n;)
    {
        file >> a[i++]; //�������� ��� ����� � ����� � �����
    }
    if (!file.is_open()) {
        printf("\n ���� %s �� ��������\n", fn);
    }
    file.close(); //�������� �����
    return 1; //���������� �������� "����"
}
