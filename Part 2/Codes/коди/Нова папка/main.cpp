#include"decl_file.h"

int main() 
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int choice;
	int n;
	Fraction* group = new Fraction[20];
	while ((choice = menu()) != 3) {
		switch (choice) {
		case 0: {// ��������� ����� �����
			cout << "\n������ ������� ����� = ";
			n = EnterNumber();
			if (n <= 0) n = 2;
			EnterArrayFrac(group, n);
		}break;
		case 1: PrintArrayFrac(group, n); break;// ���� �����
		case 2: FindOddNumerator(group, n); break;// ����������� ����� � ��������� ������������
		case 3: cout << "\n���������� ������"; break;// �����
		default: cout << "\n���i���� ���i�!\n"; break;
		}
	};
	delete[] group;// ��������� �������� ���'��
}