/* Конкатенація стрічок */
#include <iostream>
#include <string.h> /* містить опис функції strcat() */
#pragma warning(disable:4996);
using namespace std;
#define SIZE 80
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	puts("What is your favorite flower?");
	cin.getline(flower, SIZE - 1); /* зчитати не більше, ніж число SIZE-1 символів */
	strcat(flower, addon); /* копія стрічки addon дописується в кінець стрічки flower */
	puts(flower); /* нова стрічка flower - це об'єднання двох стрічок*/
	puts(addon); /* друга стрічка не змінюється*/
	puts("bye!");
	return 0;
}