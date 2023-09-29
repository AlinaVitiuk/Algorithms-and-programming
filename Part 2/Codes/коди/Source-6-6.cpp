/* Приклад 6 */
/* Масив структур з інформацією про студентів групи */
#include<iostream>
#include <Windows.h>
using namespace std;

const int size_s = 20, size_ex = 5;

struct student
{
	/* масиви символів для зберігання імені та прізвища студента*/
	char FirstName[size_s], LastName[size_s];
	/* масив екзаменаціних оцінок */
	int Marks[size_ex];
};

void main()
{
	SetConsoleOutputCP(1251); /* зміна кодування для використання кирилиці при вводі та виводі */
	SetConsoleCP(1251);
	/* Ініціалізація масиву структур */
	struct student group[] = { {"Андрiй","Козак",{5,4,4,5,4}},
				   {"Олена","Горська",{5,5,4,4,4}},
				   {"Андрiй","Петрик",{3,4,4,5,4}},
				   {"Степан","Антонюк",{5,5,5,5,3}}
	};
	/* визначення кількості елементів масиву структур*/
	int n = sizeof(group) / sizeof(student);
	/* роздрук значень полів елементів масиву структур*/
	cout << "\nРезультати сесiї:\n\n";
	for (int i = 0; i < n; i++)
	{
		/* форматоване виведення результату */
		cout.width(size_s); cout << (group + i)->LastName;
		/*або*/
		//cout << (*(group + i)).LastName;
		cout.width(size_s); cout << group[i].FirstName;
		for (int j = 0; j < size_ex; j++)
		{
			cout.width(5); cout << (group + i)->Marks[j];
		}
		cout << endl;
	}
}
