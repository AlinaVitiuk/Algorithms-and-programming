/* ������� 3 */
/* ������� �� ���� �������� */
#include<iostream>
#include<cstdlib>
using namespace std;

struct Fraction
{
	int numerator, denominator; /* ��������� � ��������� */
	void EnterFraction(const char*); /* �������� ����� */
	void PrintFraction(const char*); /* ���� ����� */
	void CreateFraction(int, int = 1); /* ������������ ������ ����� */
	void SimplifyFraction(); /* ��������� ����� */
	Fraction Sum(Fraction &); /* ���� ����� */
};

int EnterNumber(const char*); /* �������� �����*/
int CommonDivisor(int, int); /* ��������� ������� ������ */

void main()
{
	setlocale(LC_ALL, "ukr");
	struct Fraction a, d; /* ���������� ���� ������ ���� Fraction*/
	a.EnterFraction("a"); /* ������ ����-������� ��� �������� ����� */
	a.SimplifyFraction(); /* ������ ����-������� ��� ��������� ����� */
	a.PrintFraction("a");
	d = a; /* ������������� ���� ����� */
	d.CreateFraction(3, 0); d.PrintFraction("d"); /* ������������ ����� ������� ���������� � ���������� */
	struct Fraction b = { 2,3 }; b.PrintFraction("b"); /* ���������� �� ���������� ���� ����� ���� Fraction */
	a.PrintFraction("a");
	struct Fraction c = a.Sum(b); /* ��������� ����� a i b */
	c.PrintFraction("(c=a+b)");
	cout << "\nEND.\n";
}
int CommonDivisor(int a, int b) /* ��������� ������� ������ */
{
	if (!b) /* ���� b = 0 */
		return a; /* ���������� a*/
	return CommonDivisor(b, a%b); /* ����������� ������ ������� CommonDivisor, �� ������ �������� - �� ������ �� ������ a �� b */
}
int  EnterNumber(const char*ms) /* �������� �����*/
{
	cout << "����i�� " << ms << " = ";
	char s[10];
	cin.getline(s, 10); /* ������� ������� ������ */
	return atoi(s); /* ������ s ������������ � int */
}

void Fraction::EnterFraction(const char *ms) /* �������� ����� (���������� ��������� ::) */
{
	cout << "����i�� ��i� " << ms << " \n";
	numerator = (int)EnterNumber("���������"); /* �������� ���������� */
	do
	{
		denominator = (int)EnterNumber("���������"); /* �������� ���������� */
	} while (!denominator); /* ���� ��������� = 0 */
}
void Fraction::PrintFraction(const char *ms) /* ���� ����� (���������� ��������� ::) */
{
	cout << "��i� " << ms << " = " << numerator << '/' << denominator << endl;
}

void Fraction::CreateFraction(int c, int b) /* ������������ ������ ����� (���������� ��������� ::) */
{
	numerator = c; /* ������������ ������ �������� ����������*/
	denominator = (b) ? b : 1; /* ������������ ������ �������� ����������, �������� �� 0 */
}

void Fraction::SimplifyFraction() /* ��������� ����� (���������� ��������� ::) */
{
	int a = CommonDivisor(abs(numerator), abs(denominator)); /* ��������� ������� ������ ���������� � ���������� */
	numerator /= a; denominator /= a; /* ���������� ���������� � ���������� �� ��� */
	int b = abs(denominator);  a = abs(numerator);
	numerator = (numerator*denominator > 0) ? a : -a; /* ���� ��������� � ��������� ���������� �����, �� ���� ����� +, ������ -*/
	denominator = b;
}
Fraction Fraction::Sum(Fraction &b) /* ���� ����� (���������� ��������� ::) */
{
	Fraction a; /* ���������� ���� ����� ���� Fraction */
	a.denominator = denominator * b.denominator; /* ��� denominator - �� �������� ����� � ������� ��������, � ����� ��������� ����-������� Sum*/
	a.numerator = numerator * b.denominator + denominator * b.numerator; /* ��� numerator - �� ��������� ����� � ������� ��������, � ����� ��������� ����-������� Sum*/
	a.SimplifyFraction();
	return a; /* ��������� ��������� ������� - ����� ���� Fraction */
}