/* Приклад 3 */
/* Введення-виведення інформації у поля змінної типу ``структура'' */
#include <iostream>
#include<Windows.h>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251); /* зміна кодування для використання кирилиці при вводі та виводі */
	SetConsoleCP(1251);
	struct detail /* оголошення шаблону структури Деталь*/
	{
		int model_number; /* номер моделі*/
		int detail_number; /* номер деталі*/
		float detail_price; /* вартість деталі*/
	};
	/* оголошення змінних та ініціалізація однієї з них */
	detail det, det1 = { 12089, 245, 187.57f }, det2;
	/* Введення інформації у поля змінної */
	cout << "\nВведiть данi про деталь det:\n";
	cout << "\n Номер моделi = "; cin >> det.model_number;
	cout << "\n Номер деталi = "; cin >> det.detail_number;
	cout << "\n Вартiсть деталi = "; cin >> det.detail_price;
	/* Виведення інформації полів змінної */
	cout << "\nНомер моделi det : " << det.model_number << "\nНомер деталi : "
		<< det.detail_number << "\nВартiсть деталi : " << det.detail_price << " грн.\n";
	return 0;
}