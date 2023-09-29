/* Приклад 5 */
/* Масив структур координат точок на екрані */
#include <iostream>
#include<Windows.h>
using namespace std;

struct Point_2d /* оголошення шаблону структури */
{
	int left, top; /* координати точки*/
};

const int size1 = 100; /* задання константи розмірності масиву */

int vvid_chusla(const char*); /* прототип функції для введення числа з клавіатури*/

void main()
{
	SetConsoleOutputCP(1251); /* зміна кодування для використання кирилиці при вводі та виводі */
	SetConsoleCP(1251);
	int n;
	struct Point_2d screen[size1]; /* оголошення статичного масиву структур */
	do
	{
		n = vvid_chusla(" кiлькiсть точок на екранi ");
	} while (n <= 0 || n > size1);
	//Point_2d* screen = new Point_2d[n]; /*МОЖНА оголосити динамічний масив структур*/
	cout << "\n Задайте координати точок вiдносно лiвого верхнього кута екрану\n\n";
	for (int i = 0; i < n; i++)
	{
		screen[i].left = vvid_chusla(" злiва ");
		screen[i].top = vvid_chusla(" зверху ");
	}
	cout << "\nТочки екрану\n";
	for (int i = 0; i < n; i++)
	{
		cout << " \nТочка [" << i + 1 << "] = (";
		cout.width(3);  cout << (screen + i)->left << ",";
		cout.width(3);  cout << screen[i].top << " )";
	}
	cout << endl;
}
int vvid_chusla(const char*ms) /* функція для введення числа з клавіатури*/
{
	cout << "Введiть " << ms << " = ";
	char rez[10]; /* масив символів для зчитування введеної стрічки */
	cin.getline(rez, 10);
	return atoi(rez); /* перетворення стрічки до цілого числа */
}