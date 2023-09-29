//��� ������� ������������� �������� ����� A �� B �������� �������� �����������
//������ ��� ���� �����(A\B) � �������� ��������� � ����� ���� �.

#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int size_file(const char*);  //������������ ������� �������� � ����
int from_file_to_array(const char*, int*&, int&); //����� ����� � ����� � �����

int main()
{
    SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����

    const char* data1 = "A.txt", * data2 = "B.txt", * data3 = "C.txt"; //������ � ������� �����
    int* arr1 = 0, * arr2 = 0, * arr3 = 0; //arr1, arr2, arr3 - ����� ������
    int size1, size2, size3; //���� ��� ���������� ������� �������� � ������ (��������� ������)
    int i = 0, j = 0, k = 0; //���������
    
    //������������ ������� �������� � ������
    size1 = size_file(data1);
    size2 = size_file(data2);
    int n = 0; // ����� ��� ���������� ������� �������� A\B

    //�������� ���'�� �� ��������� �����
    arr3 = new int[size1];

    //����� ����� � ����� � ������
    from_file_to_array(data1, arr1, size1);
    from_file_to_array(data2, arr2, size2);

    //��������� A\B
    for (int i = 0; i < size1; i++) {
        int f = 0;
        for (int j = 0; j < size2; j++)
            if (arr1[i] == arr2[j])
                f = 1;
        if (!f)
            if (arr3[k++] = arr1[i])
                n++;
    }
    
    ofstream fout(data3); //��������� ������ ����� C.txt
    for (int k = 0; k < n; k++) {
        fout << arr3[k] << " "; //����� ����� � ����
    }
    
    if (n > 0) {
        cout << "\n���� C.txt ��������� ������� �������� � ����� A.txt i B.txt\n";
    }
    else {
        cout << "\n������� ��� ��������� ����� C.txt ������� �������� � ����� A.txt i B.txt\n";
    }

    delete[] arr1, arr2, arr3; //��������� ���'��
    fout.close();              //�������� �����
}

int size_file(const char* fn) { //������������ ������� �������� � ����
    int n = 0; // n - ������� �������� � ����
    int a;     //a - ������������ ����� ��� ��������� ��������� ������, ��������� � �����
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

int from_file_to_array(const char* fn, int*& a, int& n) { //����� ����� � ����� � �����

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