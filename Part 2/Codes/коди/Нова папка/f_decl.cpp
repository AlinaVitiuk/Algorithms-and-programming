#include"decl_file.h"

int menu() {// функція меню
	cout << "\n\t___МЕНЮ___\n вибiр задачi:\n\t";
	cout << "0 - Створити групу дробів\n\t";
	cout << "1 - Вивести на екран всі дроби\n\t";
	cout << "2 - Знайти непарні чисельники\n\t";
	cout << "3 - Вихід\n";
	cout << "Введiть Ваш вибiр = ";
	return EnterNumber();
}

int EnterNumber() {// функція вводу числа, аби уникнути потім проблем з вводом стрічок
	char rez[15];
	gets_s(rez);
	return atoi(rez);
}

void EnterArrayFrac(Fraction* a, int n) {// функція вводу дробів
	cout << "\nВводьте дроби: \n";
	for (int i = 0; i < n; i++)
		a[i].EnterFrac();
	cout << "\nДроби створено!";
}

void Fraction::EnterFrac() {// функція вводу дроба
	cout << "\nВводьте наступний дріб: ";
	cout << "\nчисельник: ";
	numerator = EnterNumber();
	cout << "\nзнаменник: ";
	denominator = EnterNumber();
}

void PrintArrayFrac(Fraction* a, int n) {// функція виводу дробів
	for (int i = 0; i < n; i++)
	{
		cout << "\n\tДріб №" << i;
		a[i].PrintFrac();
		cout << "\n";
	}
}

void Fraction::PrintFrac() {// функція виводу дроба
	cout << "\n\t" << numerator << "/" << denominator;
}

void FindOddNumerator(Fraction* a, int n) {// функція знаходження непарних чисельників
	cout << "\nДроби з непарними чисельниками: ";
	bool flag = false;// прапорець, який вказує, що є хочаби одне авто старше 5 років
	for (int i = 0; i < n; i++) {
		if (a[i].numerator % 2 != 0) {// перевірка на непарність та її вивід
			cout << "\n\tДріб №" << i;
			a[i].PrintFrac();
			cout << "\n";
			flag = true;// підняття прапорця
		}
	}
	if (flag == false) {// вивід на випадок якщо такі дроби не знайдено
		cout << "\nДробів не знайдено";
	}
}