/* ������� 2 */
/* ���������, �� ��������� ������� */
#include<iostream>
#include<string.h>
#include<Windows.h>
#pragma warning(disable:4996) /* ��������� ��� ��������� ��������� ���������� */

using namespace std;
const int size_s = 20, k_ex = 5;
enum { MinMark = 2, MaxMark = 5, MinYear = 1995, MaxYear = 2020 }; /* �������������� ��� ����� */
struct Date /* ���������, ��� ������ ���� */
{
	int Day, Month, Year; /* ����, �����, �� */
};
struct FullName /* ���������, ��� ������ ����� ��'� �������� */
{
	char FirstName[size_s], LastName[size_s]; /* ��'� �� ������� �������� */
};
struct Person /* �������� ���������, ��� ������ ��� ��� ����� */
{
	struct FullName Name; /* ����� ��'� */
	struct Date BirthDate; /* ���� ���������� */
	char Sex; /* ����� */
};

struct STUDENT /* �������� ���������, ��� ������ ���������� ��� �������� */
{
	struct Person Pers; /* ��� ��� ����� */
	struct Date AdmissionDate; /* ���� ������ � ��� */
	int Marks[k_ex]; /* ����� ������ */
};

int EnterNumber(const char*); /* �������� ���� */
Date EnterDate(const char*); /* �������� ���� */
FullName EnterName(const char*); /* �������� ������� ���� �������� */
void EnterPerson(Person*, const char*); /* �������� ����� ��� ����� */
void EnterStudent(STUDENT&, const char*); /* �������� ���������� ��� �������� */
void PrintDate(Date, char = '-'); /* ���� ����*/
void PrintName(const FullName&); /* ��������� ������� ���� ��������*/
void PrintPerson(const Person*); /* ��������� ����� ��� ����� */
void PrintStudent(const STUDENT&); /* ��������� ���������� ��� �������� */
bool IncorrectDate(Date); /* �������� ���������� ���� */

int main()
{
	SetConsoleOutputCP(1251); /* ���� ��������� ��� ������������ �������� ��� ���� �� ����� */
	SetConsoleCP(1251);
	STUDENT a = { {{"������","�������"}, {2,12,2000},'f'}, {12,7,2018}, {3,4,5,5,4} };
	/* ���������� �� ����������� ����� a ���� ``���������'' STUDENT */
	PrintStudent(a); /* ���� ������ ���������� */
	a.Marks[0] = 5; /* ���������� ����� */
	strcpy(a.Pers.Name.LastName, "�������"); /* ��i�� ��i����� */
	cout << "\n���i ���i\n"; PrintStudent(a); /* ���� �������� ���������� */
	STUDENT*A = new STUDENT[2]; /* ���������� ���������� ������ �������� */
	*A = a; /* ��������� ������� �������� ������ �������� ����� � */
	EnterStudent(A[1], " �������i ���i"); /* ��������  ������ �������� ������ �������� �������� */
	for (int i(0); i < 2; i++) /* ��������� ������ �������� */
		PrintStudent(A[i]);
	cout << "\n\n";
	return 0;
}

int EnterNumber(const char*ms) /* �������� ���� */
{
	cout << "\n������� " << ms << " = ";
	char rez[15];
	gets_s(rez);
	return atoi(rez); /* ������ rez ������������ � int */
}

Date EnterDate(const char*ms) /* �������� ���� */
/* ��������� Date -- �� ��� ����������, �� ������� ������� */
{
	Date a; /* ���������� ����� ���� ``���������'' Date */
	cout << "\n������� " << ms << " :\n";
	do {
		a.Day = EnterNumber(" ����� "); /* �������� ���� ��������� */
		a.Month = EnterNumber(" �i���� ");
		a.Year = EnterNumber("�i�");
	} while (IncorrectDate(a)); /* ���� ���� ���������� */
	return a; /* ����������� ��������� Date */
}
FullName EnterName(const char*ms) /* �������� ������� ���� �������� */
/* ��������� EnterName -- �� ��� ����������, �� ������� ������� */
{
	FullName a; /* ���������� ����� ���� ``���������'' FullName */
	cout << "\n������� " << ms << " :\n";
	cout << " ��i����� "; gets_s(a.LastName); /* �������� ���� ��������� */
	cout << " i�'� "; gets_s(a.FirstName);
	return a; /* ����������� ��������� EnterName */
}

void EnterPerson(Person*a, const char*ms) /* �������� ����� ��� ����� */
/* �������� ��������� �� ����������: */
/* ���������� �������� - �������� �� ���������, ��������� �������� - ������ ����� */
{
	cout << "\n������� " << ms << " :\n";
	a->Name = EnterName(" ���i "); /* �������� ���� ��������� Person */
	a->BirthDate = EnterDate(" ���� ����������");
	cout << " ����� (f- �i�. \t m - ���.)";
	char c; cin >> c; cin.ignore(1, '\n'); a->Sex = c;
}

void EnterStudent(STUDENT& a, const char*ms) /* �������� ���������� ��� �������� */
/* �������� ��������� �� ����������: */
/* ���������� �������� - ��������� �� ���������, ��������� �������� - ��'� ����� */
{
	cout << "\n������� " << ms << " :\n";
	EnterPerson(&(a.Pers), " ������i ���i"); /* ���������� ������ ��������� */
	a.AdmissionDate = EnterDate(" ���� ������");
	cout << " ������� �e�������� ���i�\n";
	for (int i = 0, b = 0; i < k_ex; i++) /* �������� ������ ��������*/
	{
		do
		{
			b = EnterNumber("��i���");
		} while (b < MinMark || b > MaxMark); /* ���� ������ ���������� */
		a.Marks[i] = b;
	}
}

void PrintDate(Date a, char c) /* ���� ����*/
/* �������� ��������� ���� Date �� ��������� */
{
	cout.fill('0'); cout.width(2); cout << a.Day << c;
	cout.width(2); cout << a.Month << c << a.Year;
	cout.fill(' ');
}

void PrintName(const FullName& a) /* ��������� ������� ���� ��������*/
/* �������� ��������� ����� const ���������, ����� ��������, ���� ���������� � ���������� */
{
	cout.width(size_s / 2); cout << a.LastName;
	cout.width(size_s / 2); cout << a.FirstName << "   ";
}

void PrintPerson(const Person* a) /* ��������� ����� ��� ����� */
/* �������� ��������� ����� �������� �� ��������� */
{
	char c = ':'; /* ������ ���������� */
	PrintName(a->Name); PrintDate(a->BirthDate, c);
	cout << "  " << a->Sex << "  ";
}

void PrintStudent(const STUDENT&a) /* ��������� ���������� ��� �������� */
/* �������� ��������� ����� const ��������� */
{
	PrintPerson(&a.Pers); /* ���������� ������ ����� */
	PrintDate(a.AdmissionDate);
	for (int j = 0; j < k_ex; j++)
		cout.width(5), cout << a.Marks[j];
	cout << "\n";
}

bool IncorrectDate(Date a) /* �������� ���������� ���� */
{
	if (a.Year < MinYear || a.Year > MaxYear || a.Month < 1 || a.Month > 12 || a.Day < 1 || a.Day > 31)
	{
		cout << "\n���������� ����\n";
		return true;
	}
	bool rez = false; /* true - ���� ���� ����������, false - ���� ���� �������� */
	switch (a.Month) /* �������� ������� ��� � ����� */
	{
	case 4: case 6: case 9: case 11: if (a.Day > 30) rez = true; break; /* �����, �� ����� �� 30 ��� */
	case 2: /* ����� ����� */
		if (a.Day > 29)
			rez = true;
		else
			rez = (a.Day == 29) && (a.Year % 4 || (a.Year % 100 == 0 && a.Year % 400)); break; /* ������������ �� */
	}
	if (rez == true)
	{
		cout << "\n���������� ����\n";
	}
	return rez;
}
