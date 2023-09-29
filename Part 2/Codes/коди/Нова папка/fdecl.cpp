#include"decl_file.h"

int menu() {
	cout << "\n\t___ћ≈Ќё___\n вибiр задачi:\n\t";
	cout << "0 - —творити групу\n\t";
	cout << "1 - ¬ивести на екран вс≥х ос≥б\n\t";
	cout << "2 - ¬≥дсортувати за датою народженн€\n\t";
	cout << "3 - ¬ивести особу(ос≥б) за вказаним номером телефону\n\t";
	cout << "4 - ¬ивести особу(ос≥б) за вказаним м≥с€цем народженн€\n\t";
	cout << "5 - ¬ивести особу(ос≥б) за вказаним пр≥звищем\n\t";
	cout << "6 - ¬их≥д\n";
	cout << "¬ведiть ¬аш вибiр = ";
	return EnterNumber();
}

int EnterNumber() {
	char rez[15];
	gets_s(rez);
	return atoi(rez);
}

void EnterArrayPerson(Note* a, int n) {
	cout << "\n¬водьте ос≥б: \n";
	for (int i = 0; i < n; i++)
		a[i].EnterPerson();
}

void FullName::EnterName() {
	cout << "\n¬водьте: \n";
	cout << " прiзвище "; gets_s(Surname);
	cout << " iм'€ "; gets_s(FirstName);
	cout << "по батьков≥ "; gets_s(Patronymic);
}

void Note::EnterPerson() {
	Name.EnterName();
	cout << "\n¬вед≥ть номер телефону:\n";
	gets_s(PhoneNum);
	
	cout << "\n¬вед≥ть дату народженн€: ";
	cout << "\nр≥к: ";
	do {
		Date[year] = EnterNumber();
		if (Date[year] > 2021 || Date[year] < 1900) cout << "\n¬вед≥ть коректний р≥к: ";
	} while (Date[year] > 2021 || Date[year] < 1900);
	
	cout << "\nм≥с€ць: ";
	do {
		Date[month] = EnterNumber();
		if (Date[month] < 1 || Date[month] > 12) cout << "\n¬вед≥ть коректний м≥с€ць: ";
	} while (Date[month] < 1 || Date[month] > 12);

	cout << "\nдень: ";
	switch (Date[month]) {
	case 4:case 6:case 9:case 11: {
		do {
			cout << "\n¬вед≥ть день в≥д 1 до 30: ";
			Date[day] = EnterNumber();
		} while (Date[day] < 1 || Date[day] > 30);
	}; break;
	case 2: {
		do {
			cout << "\n¬вед≥ть день в≥д 1 до 29: ";
			Date[day] = EnterNumber();
		} while (Date[day] < 1 || Date[day] > 29);
	}; break;
	default: {
		do {
			cout << "\n¬вед≥ть день в≥д 1 до 31: ";
			Date[day] = EnterNumber();
		} while (Date[day] < 1 || Date[day] > 31);
	}; break;
	}
}

void PrintArrayPerson(Note* a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tќсоба є" << i;
		a[i].PrintPerson();
		cout << "\n";
	}
}

void Note::PrintPerson() {
	Name.PrintName();
	cout << "\n\tЌомер телефону: " << PhoneNum;
	cout << "\n\tƒата народженн€: " << Date[0] << '.' << Date[1] << '.' << Date[2];
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
	cout << "\n¬вед≥ть номер телефону за €ким хочете знайти людину: ";
	gets_s(number);
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].PhoneNum, number) == 0) { 
			cout << "\n\tќсоба є" << i; 
			a[i].PrintPerson(); 
			flag = true; 
		}
	}
	if (!flag) cout << "\n\nќс≥б не знайдено";
}

void FindByMonth(Note* a, int n) {
	int month;
	bool flag = false;
	cout << "\n¬вед≥ть номер м≥с€ц€ за €ким хочете знайти ос≥б: ";
	do {
		month = EnterNumber();
		if (month < 1 || month > 12) cout << "\n¬вед≥ть коректний м≥с€ць: ";
	} while (month < 1 || month > 12);
	for (int i = 0; i < n; i++) {
		if (a[i].Date[1] == month) { cout << "\n\tќсоба є" << i; a[i].PrintPerson(); flag = true; }
	}
	if (!flag) cout << "\n\nќс≥б не знайдено";
}

void FindBySurname(Note* a, int n) {
	char Surname[size_s];
	bool flag = false;
	cout << "\n¬вед≥ть пр≥звище за €ким хочете знайти ос≥б: ";
	gets_s(Surname);
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].Name.Surname, Surname) == 0) { 
			cout << "\n\tќсоба є" << i; 
			a[i].PrintPerson(); 
			flag = true; }
	}
	if (!flag) cout << "\n\nќс≥б не знайдено";
}