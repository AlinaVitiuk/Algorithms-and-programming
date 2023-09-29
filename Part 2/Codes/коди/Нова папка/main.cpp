#include"decl_file.h"

int main() 
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int choice;
	int n;
	Fraction* group = new Fraction[20];
	while ((choice = menu()) != 3) {
		switch (choice) {
		case 0: {// створення групи дробів
			cout << "\nВведіть кількість дробів = ";
			n = EnterNumber();
			if (n <= 0) n = 2;
			EnterArrayFrac(group, n);
		}break;
		case 1: PrintArrayFrac(group, n); break;// вивід дробів
		case 2: FindOddNumerator(group, n); break;// знаходження дробів з непарними чисельниками
		case 3: cout << "\nЗавершення роботи"; break;// вихід
		default: cout << "\nНевiрний вибiр!\n"; break;
		}
	};
	delete[] group;// видалення динамічної пам'яті
}