#include"decl_file.h"

int menu() {
	cout << "\n\t___����___\n ���i� �����i:\n\t";
	cout << "0 - �������� �����\n\t";
	cout << "1 - ������� �� ����� ��� ���\n\t";
	cout << "2 - ³���������� �� ����� ����������\n\t";
	cout << "3 - ������� �����(���) �� �������� ������� ��������\n\t";
	cout << "4 - ������� �����(���) �� �������� ������ ����������\n\t";
	cout << "5 - ������� �����(���) �� �������� ��������\n\t";
	cout << "6 - �����\n";
	cout << "����i�� ��� ���i� = ";
	return EnterNumber();
}

int EnterNumber() {
	char rez[15];
	gets_s(rez);
	return atoi(rez);
}

void EnterArrayPerson(Note* a, int n) {
	cout << "\n������� ���: \n";
	for (int i = 0; i < n; i++)
		a[i].EnterPerson();
}

void FullName::EnterName() {
	cout << "\n�������: \n";
	cout << " ��i����� "; gets_s(Surname);
	cout << " i�'� "; gets_s(FirstName);
	cout << "�� ������� "; gets_s(Patronymic);
}

void Note::EnterPerson() {
	Name.EnterName();
	cout << "\n������ ����� ��������:\n";
	gets_s(PhoneNum);
	
	cout << "\n������ ���� ����������: ";
	cout << "\n��: ";
	do {
		Date[year] = EnterNumber();
		if (Date[year] > 2021 || Date[year] < 1900) cout << "\n������ ��������� ��: ";
	} while (Date[year] > 2021 || Date[year] < 1900);
	
	cout << "\n�����: ";
	do {
		Date[month] = EnterNumber();
		if (Date[month] < 1 || Date[month] > 12) cout << "\n������ ��������� �����: ";
	} while (Date[month] < 1 || Date[month] > 12);

	cout << "\n����: ";
	switch (Date[month]) {
	case 4:case 6:case 9:case 11: {
		do {
			cout << "\n������ ���� �� 1 �� 30: ";
			Date[day] = EnterNumber();
		} while (Date[day] < 1 || Date[day] > 30);
	}; break;
	case 2: {
		do {
			cout << "\n������ ���� �� 1 �� 29: ";
			Date[day] = EnterNumber();
		} while (Date[day] < 1 || Date[day] > 29);
	}; break;
	default: {
		do {
			cout << "\n������ ���� �� 1 �� 31: ";
			Date[day] = EnterNumber();
		} while (Date[day] < 1 || Date[day] > 31);
	}; break;
	}
}

void PrintArrayPerson(Note* a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\n\t����� �" << i;
		a[i].PrintPerson();
		cout << "\n";
	}
}

void Note::PrintPerson() {
	Name.PrintName();
	cout << "\n\t����� ��������: " << PhoneNum;
	cout << "\n\t���� ����������: " << Date[0] << '.' << Date[1] << '.' << Date[2];
}

void FullName::PrintName() {
	cout.width(size_s / 2); cout << Surname;
	cout.width(size_s / 2); cout << FirstName;
	cout.width(size_s / 2); cout << Patronymic << '\t';
}

Note* SortArrayPerson(Note* a, int n) {
	int k = n;
	bool flag = true;
	while (flag && k > 1) {
		flag = false;
		k--;
		for (int i = 0; i < k; i++) {
			if (a[i].Date[year] > a[i + 1].Date[year]) {
				Note temp = a[i];
				a[i]= a[i + 1];
				a[i + 1] = temp;
				flag = true;
			}
			else if(a[i].Date[year] == a[i + 1].Date[year]){
				if (a[i].Date[month] > a[i + 1].Date[month]) {
					Note temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
					flag = true;
				}
				else if (a[i].Date[month] == a[i + 1].Date[month]) {
					if (a[i].Date[day] > a[i + 1].Date[day]) {
						Note temp = a[i];
						a[i] = a[i + 1];
						a[i + 1] = temp;
						flag = true;
					}
				}
			}
		}
	}
	return a;
}

void FindByNum(Note* a, int n) {
	char number[size_phone];
	bool flag = false;
	cout << "\n������ ����� �������� �� ���� ������ ������ ������: ";
	gets_s(number);
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].PhoneNum, number) == 0) { 
			cout << "\n\t����� �" << i; 
			a[i].PrintPerson(); 
			flag = true; 
		}
	}
	if (!flag) cout << "\n\n��� �� ��������";
}

void FindByMonth(Note* a, int n) {
	int month;
	bool flag = false;
	cout << "\n������ ����� ����� �� ���� ������ ������ ���: ";
	do {
		month = EnterNumber();
		if (month < 1 || month > 12) cout << "\n������ ��������� �����: ";
	} while (month < 1 || month > 12);
	for (int i = 0; i < n; i++) {
		if (a[i].Date[1] == month) { cout << "\n\t����� �" << i; a[i].PrintPerson(); flag = true; }
	}
	if (!flag) cout << "\n\n��� �� ��������";
}

void FindBySurname(Note* a, int n) {
	char Surname[size_s];
	bool flag = false;
	cout << "\n������ ������� �� ���� ������ ������ ���: ";
	gets_s(Surname);
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].Name.Surname, Surname) == 0) { 
			cout << "\n\t����� �" << i; 
			a[i].PrintPerson(); 
			flag = true; }
	}
	if (!flag) cout << "\n\n��� �� ��������";
}