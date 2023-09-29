/* Приклад 2 */
/* Структури, як аргументи функцій */
#include<iostream>
#include<string.h>
#include<Windows.h>
#pragma warning(disable:4996) /* директива для уникнення неістотних повідомлень */

using namespace std;
const int size_s = 20, k_ex = 5;
enum { MinMark = 2, MaxMark = 5, MinYear = 1995, MaxYear = 2020 }; /* перелічувальний тип даних */
struct Date /* структура, яка зберігає дату */
{
	int Day, Month, Year; /* день, місяць, рік */
};
struct FullName /* структура, яка зберігає повне ім'я студента */
{
	char FirstName[size_s], LastName[size_s]; /* ім'я та прізвище студента */
};
struct Person /* вкладена структура, яка зберігає дані про особу */
{
	struct FullName Name; /* повне ім'я */
	struct Date BirthDate; /* дата народження */
	char Sex; /* стать */
};

struct STUDENT /* вкладена структура, яка зберігає інформацію про студента */
{
	struct Person Pers; /* дані про особу */
	struct Date AdmissionDate; /* дата вступу у ВНЗ */
	int Marks[k_ex]; /* масив оцінок */
};

int EnterNumber(const char*); /* введення чила */
Date EnterDate(const char*); /* введення дати */
FullName EnterName(const char*); /* введення повного імені студента */
void EnterPerson(Person*, const char*); /* введення даних про особу */
void EnterStudent(STUDENT&, const char*); /* введення інформації про студента */
void PrintDate(Date, char = '-'); /* друк дати*/
void PrintName(const FullName&); /* виведення повного імені студента*/
void PrintPerson(const Person*); /* виведення даних про особу */
void PrintStudent(const STUDENT&); /* виведення інформації про студента */
bool IncorrectDate(Date); /* перевірка коректності дати */

int main()
{
	SetConsoleOutputCP(1251); /* зміна кодування для використання кирилиці при вводі та виводі */
	SetConsoleCP(1251);
	STUDENT a = { {{"Галина","Станько"}, {2,12,2000},'f'}, {12,7,2018}, {3,4,5,5,4} };
	/* оголошення та ініціалізація змінної a типу ``структура'' STUDENT */
	PrintStudent(a); /* друк наявної інформації */
	a.Marks[0] = 5; /* перезданий іспит */
	strcpy(a.Pers.Name.LastName, "Чубенко"); /* змiна прiзвища */
	cout << "\nНовi данi\n"; PrintStudent(a); /* друк оновленої інформації */
	STUDENT*A = new STUDENT[2]; /* оголошення динамічного масиву структур */
	*A = a; /* присвоєння першому елементу масиву значення змінної а */
	EnterStudent(A[1], " наступнi данi"); /* введення  нового елемента масиву структур студентів */
	for (int i(0); i < 2; i++) /* виведення масиву структур */
		PrintStudent(A[i]);
	cout << "\n\n";
	return 0;
}

int EnterNumber(const char*ms) /* введення чила */
{
	cout << "\nВводьте " << ms << " = ";
	char rez[15];
	gets_s(rez);
	return atoi(rez); /* стрічка rez конвертується в int */
}

Date EnterDate(const char*ms) /* введення дати */
/* структура Date -- це тип результату, що повертає функція */
{
	Date a; /* оголошення змінної типу ``структура'' Date */
	cout << "\nВводьте " << ms << " :\n";
	do {
		a.Day = EnterNumber(" число "); /* введення полів структури */
		a.Month = EnterNumber(" мiсяць ");
		a.Year = EnterNumber("рiк");
	} while (IncorrectDate(a)); /* поки дата некоректна */
	return a; /* повертається структура Date */
}
FullName EnterName(const char*ms) /* введення повного імені студента */
/* структура EnterName -- це тип результату, що повертає функція */
{
	FullName a; /* оголошення змінної типу ``структура'' FullName */
	cout << "\nВводьте " << ms << " :\n";
	cout << " прiзвище "; gets_s(a.LastName); /* введення полів структури */
	cout << " iм'я "; gets_s(a.FirstName);
	return a; /* повертається структура EnterName */
}

void EnterPerson(Person*a, const char*ms) /* введення даних про особу */
/* передача параметру за вказівником: */
/* формальний параметр - вказівник на структуру, фактичний параметр - адреса змінної */
{
	cout << "\nВводьте " << ms << " :\n";
	a->Name = EnterName(" данi "); /* введення полів структури Person */
	a->BirthDate = EnterDate(" дату народження");
	cout << " стать (f- жiн. \t m - чол.)";
	char c; cin >> c; cin.ignore(1, '\n'); a->Sex = c;
}

void EnterStudent(STUDENT& a, const char*ms) /* введення інформації про студента */
/* передача параметру за посиланням: */
/* формальний параметр - посилання на структуру, фактичний параметр - ім'я змінної */
{
	cout << "\nВводьте " << ms << " :\n";
	EnterPerson(&(a.Pers), " особовi данi"); /* передається адреса структури */
	a.AdmissionDate = EnterDate(" дату вступу");
	cout << " Вводьте рeзультати сесiї\n";
	for (int i = 0, b = 0; i < k_ex; i++) /* введення оцінок студента*/
	{
		do
		{
			b = EnterNumber("оцiнку");
		} while (b < MinMark || b > MaxMark); /* поки оцінка некоректна */
		a.Marks[i] = b;
	}
}

void PrintDate(Date a, char c) /* друк дати*/
/* передача параметру типу Date за значенням */
{
	cout.fill('0'); cout.width(2); cout << a.Day << c;
	cout.width(2); cout << a.Month << c << a.Year;
	cout.fill(' ');
}

void PrintName(const FullName& a) /* виведення повного імені студента*/
/* передача параметру через const посилання, тобто параметр, який передається є константою */
{
	cout.width(size_s / 2); cout << a.LastName;
	cout.width(size_s / 2); cout << a.FirstName << "   ";
}

void PrintPerson(const Person* a) /* виведення даних про особу */
/* передача параметру через вказівник на константу */
{
	char c = ':'; /* символ розділювача */
	PrintName(a->Name); PrintDate(a->BirthDate, c);
	cout << "  " << a->Sex << "  ";
}

void PrintStudent(const STUDENT&a) /* виведення інформації про студента */
/* передача параметру через const посилання */
{
	PrintPerson(&a.Pers); /* передається адреса змінної */
	PrintDate(a.AdmissionDate);
	for (int j = 0; j < k_ex; j++)
		cout.width(5), cout << a.Marks[j];
	cout << "\n";
}

bool IncorrectDate(Date a) /* перевірка коректності дати */
{
	if (a.Year < MinYear || a.Year > MaxYear || a.Month < 1 || a.Month > 12 || a.Day < 1 || a.Day > 31)
	{
		cout << "\nНекоректна дата\n";
		return true;
	}
	bool rez = false; /* true - якщо дата некоректна, false - якщо дата коректна */
	switch (a.Month) /* перевірка кількості днів у місяці */
	{
	case 4: case 6: case 9: case 11: if (a.Day > 30) rez = true; break; /* місяці, які мають по 30 днів */
	case 2: /* місяць лютий */
		if (a.Day > 29)
			rez = true;
		else
			rez = (a.Day == 29) && (a.Year % 4 || (a.Year % 100 == 0 && a.Year % 400)); break; /* невисокосний рік */
	}
	if (rez == true)
	{
		cout << "\nНекоректна дата\n";
	}
	return rez;
}
