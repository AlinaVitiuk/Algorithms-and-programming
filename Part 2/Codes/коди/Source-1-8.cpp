#include <iostream>
using namespace std;
void main()
{
	int ar_int[] = { 2, 4, 0, 8, 9, -4 }; // ������� �� ����������� ������
	int* ptr_ar_1, * ptr_ar_2; // ���������� ���� ��������� �� ����� ���
	ptr_ar_1 = ar_int;// ��� �����
	// ar_int=ptr_ar_1;// ��� �� �����,
	//�� ��'� ���������� ������ �� ���������-��������
	ptr_ar_2 = &ar_int[0];// ��� �����, �� ���������� ������ ������� �������� ������
	cout << "*ptr_ar_1 = " << *ptr_ar_1 << "\t*ptr_ar_2 = " << *ptr_ar_2 << "\n";
	int n = sizeof(ar_int) / sizeof(ar_int[0]); // ������������ ������ ������.
	for (int i = 0; i < n; i++)
	{
		ptr_ar_2 = &ar_int[i]; cout << ar_int[i] << "\t"
			<< ptr_ar_1[i] << "\t" << *ptr_ar_2 << "\n";
	}
	cout << "*(ptr_ar_2=&ar_int[n]) = " << *(ptr_ar_2 = &ar_int[n]) << endl;
}