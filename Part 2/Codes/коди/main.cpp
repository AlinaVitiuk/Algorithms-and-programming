#include "decl_file.h"

int main()
{
    int n;
    do {
        cout << "\nEnter 0 if you want to exit";
        cout << "\nEnter a natural number = ";
        cin >> n;
        int exit = n;//�����, �� ������� ��� ������, ������� n � ���������� ����� 0
        if (exit == 0) return 0; //�������� �� ����� � ��������
        n = (n < 0) ? -n : n; //�������� �� ����� �� � ��'�����
        stack* top = NULL;//������� �������
        do {
            AddtoStack(top, n % 10);
            //��������� ������ �������� ����� �� ����� ���� ������ �� ������ �� 10
            n /= 10;//��������� �����, ��� ������� ������
        } while (n != 0); //�������� ��������� ����� �� �����
        cout << "\nSeparated digits " << " = " << "\t";
        PrintStack(top);
        cout << "\nDigits are used: ";
        QuantityOfDigits(top);
        DestroyStack(top);
    } while (exit != 0);//���� ��� �� ������ � ��������
    return 0;
}