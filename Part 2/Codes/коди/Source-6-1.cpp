/* Приклад 1 */
/* Визначення розміру пам'яті, який займає змінна типу ``структура'' в ОП */
#include <iostream>
using namespace std;
int main()
{
	struct stuff /* оголошення шаблону структури */
	{
		int number; /* 4 байти */
		char code[4]; /* 4 по 1 байту*/
		float cost; /* 4 байти*/
	} a1;
	cout << "sizeof a1 =" << sizeof(a1) << "\n";
	return 0;
}