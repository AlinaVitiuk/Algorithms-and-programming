// ������������ ������ ���������� ������� (��������� ���������) �� ����������� ��� �������� �� ��������, 
// �������������� ����� ���������, � ����� ������� �������������� �������.//��������  ������ ������������ �� �������������://��� ������� a[i] = cos(2 * i + 0.5) + 1.5;//��� ������� b[i] = sin(3 * i + 1.5) + 1.2.// ������ ����� � // ������ ����� � #include <iostream>
#include <math.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

void sort(double*, int);//�������� ������� ����������
void output(double*, int);//�������� ������� ������

int main()
{
    SetConsoleOutputCP(1251);//������� ������ ��������� ����
    int len_a, len_b; //������� ������
    cout << "\n������ ��������� ������ �= ";
    do {
        cin >> len_a;
        if (len_a < 1) cout << "\n������ �������� ��������� ����� 0" << "\t A=";
    } while (len_a < 1);//�������� ����������� �������� �����
    double* a = new double[len_a];//������� ��������� ������ �
    cout << "\n������������ ����� �:";
    for (int i = 0; i < len_a; i++)//��������� ������ �
    {
        *(a + i) = cos(2 * (double)i + 0.5) + 0.5;
        cout << setw(10) << '\n' << *(a + i);
    }

    cout << "\n������ ��������� ������ B= ";
    do {
        cin >> len_b;
        if (len_b < 1) cout << "\n������ �������� ��������� ����� 0" << "\t B=";
    } while (len_b < 1);//�������� ����������� �������� �����
    double* b = new double[len_b];// ������� ��������� ������ �
    cout << "\n������������ ����� B:";
    for (int i = 0; i < len_b; i++)//��������� ������ �
    {
        *(b + i) = sin(3 * (double)i + 1.5) + 1.2;
        cout << setw(10) << '\n' << *(b + i);
    }

    cout << "\n\n³����������� ����� �:";
    sort(a, len_a);//���������� ������ �
    output(a, len_a);//���� ������ �


    cout << "\n\n³����������� ����� B:";
    sort(b, len_b);//���������� ������ �
    output(b, len_b);//���� ������ �

    cout << "\n\n³����������� ��'������� ����� �:";
    int len_c = len_a + len_b;//��������� ���� ��������� ��� ������ �
    double* c = new double[len_c];//���������� ������ �
    for (int i = 0; i < len_a; i++) {//���������� ������ � ���������� � �
        *(c + i) = *(a + i);
    }
    for (int i = 0; i < len_b; i++) {//���������� ������ � ���������� � �
        *(c + i + len_a) = *(b + i);
    }
    sort(c, len_c);//���������� ������ �
    output(c, len_c);//���� ������ �
    delete[] a, b, c;// ���������� ���'��

}

void sort(double* x, int k) { //������� ����������
    int p = 1;
    while (p && k > 1) {
        p = 0, k--;
        for (int i = 0; i < k; i++) {
            if (*(x + i) < *(x + i + 1)) {
                double dodatk = *(x + i);
                *(x + i) = *(x + i + 1);
                *(x + i + 1) = dodatk;
                p = 1;
            }
        }
    }
}

void output(double* x, int k) { //������� ������
    for (int i = 0; i < k; i++)
    {
        cout << setw(10) << '\n' << *(x + i);
    }
}