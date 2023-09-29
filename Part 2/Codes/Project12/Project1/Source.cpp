#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int SizeOfFile(const char*);  //������������ ������� �������� � ����
int FromFileToArr(const char*, int*&, int&); //����� ����� � ����� � �����

int main()
{
    SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����

    const char* a_name = "A.txt", * b_name = "B.txt", * c_name = "C.txt"; //������ � ������� �����
    int* arr1 = 0, * arr2 = 0, * arr3 = 0; //a, b, c - ����� ������
    int sizea, sizeb, sizec; //���� ��� ���������� ������� �������� � ������ (��������� ������)
    int i = 0, j = 0, k = 0; //���������

    //������������ ������� �������� � ������
    sizea = SizeOfFile(a_name);
    sizeb = SizeOfFile(b_name);
    int n = 0; // ����� ��� ���������� ������� �������� A\B

    //�������� ���'�� �� ��������� �����
    arr3 = new int[sizea];

    //����� ����� � ����� � ������
    FromFileToArr(a_name, arr1, sizea);
    FromFileToArr(b_name, arr2, sizeb);

    //��������� A\B
    for (int i = 0; i < sizea; i++)
    {
        int f = 0;
        for (int j = 0; j < sizeb; j++)
            if (arr1[i] == arr2[j])
                f = 1;
        if (!f)
            if (arr3[k++] = arr1[i])
                n++;
    }

    ofstream fout(c_name); //��������� ������ ����� C.txt
    for (int k = 0; k < n; k++)
    {
        fout << arr3[k] << " "; //����� ����� � ����
    }

    if (n > 2) {
        cout << "\n���� ff.txt ��������� ������� �������� � ����� A.txt i B.txt\n";
    }
    else {
        cout << "\n������� ��� ��������� ����� C.txt ������� �������� � ����� A.txt i B.txt\n";
    }
    delete[] arr1, arr2, arr3; //��������� ���'��
    fout.close(); //�������� �����
}

int SizeOfFile(const char* fn) {
    int n = 0; // n - ������� �������� � ����
    int a; //����� ��� ��������� ��������� �����
    ifstream fin;
    fin.open(fn);
    while (!fin.eof()) //���� �� ��������� ���� �����
    {
        fin >> a;
        n++;
    }
    fin.close(); //�������� �����
    return n ? n : -1; //���������� ������� �������� � ���� ��� -1, ���� ���� �������
}

int FromFileToArr(const char* fn, int*& a, int& n) //����� ����� � ����� � �����
{
    ifstream file;
    file.open(fn);
    n = SizeOfFile(fn); //������������ ������� �������� � ����
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