/* ������� 5 */
/* ������� ��������� */
#include <iostream>
using namespace std;
template <class A, class B> /* ��������� �������� ��������� T_Struct */
struct T_Struct /* ������ ���� ��������� */
{
	A a; B b; /* ���� ���� ��������� */
};
typedef T_Struct <int, int> t_type; /* t_type - ���� ��'� ��� ��������� T_Struct � ����� ������ ������ */

template <class A, class B> /* ���������� �������� ��������� T_Struct_2 */
struct T_Struct_2 /* ������ ���� ��������� */
{
	A a; B b; /* ���� ���� ��������� */
};
int main()
{
	t_type obj = { 1,2 }; /* ���������� ����� ���� ��������� � ����� ������ ������ */
	T_Struct_2<double, double> dane = { 3.14,2.72 }; /* ���������� ����� ���� ��������� � ����� ������� ������ */
	cout << "\n\tobj = " << obj.a << "\t" << obj.b << endl; /* ��������� ���� ��������� �� ����� */
	cout << "\n\tdane = " << dane.a << "\t" << dane.b << endl;
	return 0;
}