#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning (disable :4996)

using namespace std;

void print_str(char**, int);
char** insert_line(char**, int&, int&);
void sort_lines(char**, int);


int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    int len = 0, n = 0; // len - ������� ������, n - ������� ������ � �����
    char** array = 0;

    cout << "������ ��� �����(��� ���������� ��������� ����� ENTER ����� ������):\n";
    do {
        array = insert_line(array, n, len);
    } while (len != 0);

    if (n != 0) { // �������� �� ������� �� �� ������ �����
        cout << "\n������ ������:\n";
        print_str(array, n);
        cout << "\n³��������� ������:\n";
        sort_lines(array, n);
        print_str(array, n);

        for (int i = 0; i < n; i++) { // ��������� �������� ���'��
            delete[]array[i];
        }
        delete[]array;
    }
    else { // ��������� �� �������, ���� ������ �� �������
        cout << "\n������ �� ������\n";
        delete[]array;
    }
    return 0;
}

void print_str(char** arr, int n) { // ������� ������
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << endl;
}

char** insert_line(char** arr, int& n, int& len) { // ������� ������� ���� ������
    char str[BUFSIZ];
    gets_s(str);
    len = int(strlen(str)); // ����������� ������� ������

    if (len != 0) { // �������� �� �������, ���� ������ �����
        char** lines = new char* [++n];
        for (int i = 0; i < n; i++) {
            *(lines + i) = new char[len + 1];
            if (i == n - 1) strcpy(*(lines + i), str); // ���������� ���� ������
            else *(lines + i) = *(arr + i); // ���������� ������ ������ ������ �������
        }
        return lines;
    }
    else {
        return arr;
    }
}

void sort_lines(char** arr, int n) { // ������������� ������(����� �������� �� ������� �� ����������)
    int k = n;
    bool flag = true;
    while (flag && k > 1) { // ����� �������
        flag = false;
        k--;
        for (int i = 0; i < k; i++) {
            if (strlen(*(arr + i)) > strlen(*(arr + i + 1))) { // ����� ������, ���� ��������� ������ � ������
                char* temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                flag = true;
            }
        }
    }
}