#include <iostream>
using namespace std;
int w = 3, p = 5, q = 2; //�������� ����
const int k = 4, a = 5;
const static int n;
void main()
{
	/*���'��� �� �������� ���� ���������� ���������*/
	cout << "w = " << w << "\t&w = " << &w << endl;
	cout << "p = " << p << "\t&p = " << &p << endl;
	cout << "q = " << q << "\t&q = " << &q << endl;
	/*������ ������ w,p,q ����������� �� 4 �����*/
	cout << "\nk = " << k << "\t&k = " << &k << endl;
	cout << "a = " << a << "\t&a = " << &a << endl;
	cout << "n = " << n << "\t&n = " << &n << endl;
	/*������ �� ��������� ��������� ������� � ������
	�������, ��� ����� ���������*/
}