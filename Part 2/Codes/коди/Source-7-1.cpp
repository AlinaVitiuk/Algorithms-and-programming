/* Приклад 1 */
/* Вкладені структури */
#include<iostream>
#include<Windows.h>
#include<string.h> /* містить прототипи стрічкових функцій */
#pragma warning(disable:4996) 
/* директива для уникнення неістотних повідомлень -
дозволяє вважати зміни в ідентифікаторах функцій неістотними */
using namespace std;
const int size_s = 20, k_ex = 5;
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
void main()
{
	SetConsoleOutputCP(1251); /* зміна кодування для використання кирилиці при вводі та виводі */
	SetConsoleCP(1251);
	STUDENT a = { {{"Галина","Станько"}, {2,12,2000}, 'f'}, {12,7,2018}, {3,4,5,5,4} };
	/* оголошення та ініціалізація змінної a типу ``структура'' STUDENT */
	cout << "Розмiр структури STUDENT = " << sizeof(STUDENT) << endl;
	/* розмір памяті, який займатиме змінна типу ``структура'' STUDENT */
	cout.width(size_s / 2); cout << a.Pers.Name.LastName;
	/* виділяє для наступного виводу поле шириною size_s/2 позицій */
	/* і виводить на екран Прізвище студента*/
	cout.width(size_s / 2); cout << a.Pers.Name.FirstName << "   ";
	/* виділяє для наступного виводу поле шириною size_s/2 позицій */
	/* і виводить на екран Ім'я студента*/
	cout.fill('0'); /* заповнює решту полів для наступного виводу символом '0' */
	cout.width(2); cout << a.Pers.BirthDate.Day << '-';
	cout.width(2); cout << a.Pers.BirthDate.Month << '-' << a.Pers.BirthDate.Year;
	/* виводить на екран дату народження студента */
	cout.fill(' '); /* заповнює решту полів для наступного виводу символом ' ' */
	cout.width(4); cout << a.Pers.Sex << "   "; /* виводить на екран стать студента */
	cout.fill('0'); cout.width(2); cout << a.AdmissionDate.Day << '-'; 
	cout.width(2); cout << a.AdmissionDate.Month << '-' << a.AdmissionDate.Year;
	/* виводить на екран дату зарахування студента до ВНЗ */
	cout.fill(' ');
	for (int j = 0; j < k_ex; j++) /* виводить на екран усі оцінки студента*/
		cout.width(5), cout << a.Marks[j];
	cout << "\n\n";

	/* Зміна деяких полів у вкладених структурах */
	a.Marks[0] = 5; /* перезданий іспит */
	strcpy(a.Pers.Name.LastName, "Чубенко");	/* зміна Прізвища */
	cout << "\nНовi данi\n"; /* виводить оновлену інформацію */
	cout.width(size_s / 2); cout << a.Pers.Name.LastName;
	cout.width(size_s / 2); cout << a.Pers.Name.FirstName << "   ";
	cout.fill('0'); cout.width(2); cout << a.Pers.BirthDate.Day << '-';
	cout.width(2); cout << a.Pers.BirthDate.Month << '-' << a.Pers.BirthDate.Year; cout.fill(' ');
	cout.width(4); cout << a.Pers.Sex << "   ";
	cout.fill('0'); cout.width(2); cout << a.AdmissionDate.Day << '-'; cout.width(2);
	cout << a.AdmissionDate.Month << '-' << a.AdmissionDate.Year; cout.fill(' ');
	for (int j = 0; j < k_ex; j++)
		cout.width(5), cout << a.Marks[j];
	cout << "\n\n";
}