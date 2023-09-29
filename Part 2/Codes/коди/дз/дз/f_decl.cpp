#include"decl_file.h"

/* �������� ����� */
int EnterNumber() 
{
	char rez[15];
	gets_s(rez);
	return atoi(rez);
}

/* �������� ����� */
void EnterArrayFraction(Fraction* a, int n) 
{
	cout << "\n�����! ������� ��������� �����.";
	cout << "\n������ ����� a / b (a - ���������, b - ���������)\n";
	for (int i = 0; i < n; i++)
		a[i].EnterFraction();
	cout << "\n����� �������\n";
}

/* �������� ����� */
void PrintArrayFraction(Fraction* a, int n) 
{
	cout << "\n������ �����:";
	for (int i = 0; i < n; i++)
	{
		cout << "\n���_" << i;
		a[i].PrintFraction();
	}
	cout << "\n";
}

/*����� � ��������� ������������ */
void SearchArrayFraction(Fraction* a, int n) 
{
	cout << "\n����� � ��������� ������������: ";
	bool flag = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i].numerator % 2 != 0) 
		{
			cout << "\n���_" << i;
			a[i].PrintFraction();
			flag = 1;
		}
		if (flag == 0) 
		{
			cout << "\n����� � ��������� ������������ �� ��������";
		}
	}
	cout << "\n";
}

/* �������� ����������� ����� */
void Fraction::EnterFraction() 
{ 
	do
	{
		cout << "\n������� ���: \n";
		cout << "a: ";
		numerator = (int)EnterNumber();
		cout << "b: ";
		denominator = (int)EnterNumber();
		if (numerator != 1 && (denominator % numerator != 0 || numerator % denominator != 0))
		{
			cout <<"������� ��������� �����\n" ;
		}
	} while (numerator !=1 && denominator % numerator == 0 || numerator % denominator == 0);

}

/* ���� ����� */
void Fraction::PrintFraction() {
	cout << "     " << numerator << "/" << denominator;
}

