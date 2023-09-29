#include"decl_file.h"

int menu() {// ������� ����
	cout << "\n\t___����___\n ���i� �����i:\n\t";
	cout << "0 - �������� ����� �����\n\t";
	cout << "1 - ������� �� ����� �� �����\n\t";
	cout << "2 - ������ ������ ����������\n\t";
	cout << "3 - �����\n";
	cout << "����i�� ��� ���i� = ";
	return EnterNumber();
}

int EnterNumber() {// ������� ����� �����, ��� �������� ���� ������� � ������ ������
	char rez[15];
	gets_s(rez);
	return atoi(rez);
}

void EnterArrayFrac(Fraction* a, int n) {// ������� ����� �����
	cout << "\n������� �����: \n";
	for (int i = 0; i < n; i++)
		a[i].EnterFrac();
	cout << "\n����� ��������!";
}

void Fraction::EnterFrac() {// ������� ����� �����
	cout << "\n������� ��������� ���: ";
	cout << "\n���������: ";
	numerator = EnterNumber();
	cout << "\n���������: ";
	denominator = EnterNumber();
}

void PrintArrayFrac(Fraction* a, int n) {// ������� ������ �����
	for (int i = 0; i < n; i++)
	{
		cout << "\n\t��� �" << i;
		a[i].PrintFrac();
		cout << "\n";
	}
}

void Fraction::PrintFrac() {// ������� ������ �����
	cout << "\n\t" << numerator << "/" << denominator;
}

void FindOddNumerator(Fraction* a, int n) {// ������� ����������� �������� ����������
	cout << "\n����� � ��������� ������������: ";
	bool flag = false;// ���������, ���� �����, �� � ������ ���� ���� ������ 5 ����
	for (int i = 0; i < n; i++) {
		if (a[i].numerator % 2 != 0) {// �������� �� ��������� �� �� ����
			cout << "\n\t��� �" << i;
			a[i].PrintFrac();
			cout << "\n";
			flag = true;// ������� ��������
		}
	}
	if (flag == false) {// ���� �� ������� ���� ��� ����� �� ��������
		cout << "\n����� �� ��������";
	}
}