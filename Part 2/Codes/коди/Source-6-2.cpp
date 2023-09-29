/* Приклад 2 */
/* Ініціалізація змінної типу ``структура'' */
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
	/* знаходження розміру пам'яті, виділеної під змінну det */
	cout << "\nРозмiр даного типу detail = " << sizeof(det) << " байтiв.\n";
	return 0;
}