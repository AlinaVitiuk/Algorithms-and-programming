/* Приклад 4 */
/* Операції над структурами */
#include <iostream>
#include<Windows.h>
using namespace std;

struct detail
{
	int model_number; /* номер моделі*/
	int detail_number; /* номер деталі*/
	float detail_price; /* вартість деталі*/
};

void main()
{
	SetConsoleOutputCP(1251); /* зміна кодування для використання кирилиці при вводі та виводі */
	SetConsoleCP(1251);
	struct detail det, det1 = { 12089,245,187.57f }, det2;
	cout << "\nРозмiр даного типу detail = " << sizeof(det) << " байтiв.\n";
	cout << "\nНомер моделi det1 : " << det1.model_number << "\nНомер деталi : "
		<< det1.detail_number << "\nВартiсть деталi : " << det1.detail_price << " грн.\n";

	det2 = det1; /* присвоєння одній змінній значення іншої структурної змінної */
	detail*pd = &det1; /* присвоєння адреси структурної змінної */
	det = *pd; /* присвоєння значення змінній за адресою іньшої структурної змінної */
	det.detail_number = 125; /* присвоєння значення полю структурної змінної */
	pd = &det; /* присвоєння адреси структурної змінної */

	cout << "\nНомер моделi det : " << det.model_number << "\nНомер деталi : "
		<< pd->detail_number << "\nВартiсть деталi : " << pd->detail_price << " грн.\n";
	cout << "\nНомер моделi det2 : " << det1.model_number << "\nНомер деталi : "
		<< det1.detail_number << "\nВартiсть деталi : " << det1.detail_price << " грн.\n";

	pd = new detail;
	(*pd).detail_number = 101; /* надання вмістимому поля значення за адресою, що у вказівникові */
	pd->detail_number = 12101; /* надання вмістимому поля значення за адресою, що у вказівникові */
	pd->detail_price = 256.08f;

	cout << "\nНомер  нової моделi : " << pd->model_number << "\nНомер цiєї деталi : "
		<< pd->detail_number << "\nВартiсть деталi : " << pd->detail_price << " грн.\n";
}