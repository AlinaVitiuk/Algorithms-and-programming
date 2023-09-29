#include<iostream>      // опосередковано під'єднується файл stdio.h
#include<string.h>      // містить прототипи стрічкових функцій 
#include <ctype.h>      // містить функції, які встановлюють приналежність символу до відповідної групи
#include <Windows.h>    // підключення заголовного файлу

using namespace std;
const int size1 = 100; //
void main()
{
	SetConsoleOutputCP(1251);    //Встановлення кодування Windows-1251 для виведення даних
	SetConsoleCP(1251);          //Встановлення кодування Windows-1251 для введення даних
	char c_end = '.';            //символ завершення рядка
	char str[size1] = " ";       //порожній масив символів розмірністю size1
	int n = size1 - 1; int i = 0;
	cout << "\nВведіть текст\n";
	cout << "\nПісля введення бажаного тексту введіть « . » та натисніть ENTER\n";
	while (i < n && ((str[i] = getchar()) != c_end))i++;
	str[i] = '\0'; n = i;
	cout << "\nВведений текст має " << (n) << " символів\n" << str << endl;

}