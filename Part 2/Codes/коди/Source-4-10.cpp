#include<iostream>
const int size1 = 20;
using namespace std;
void main()
{
	SetConsoleOutputCP(1251);    //Встановлення кодування Windows-1251 для виведення даних
	SetConsoleCP(1251);          //Встановлення кодування Windows-1251 для введення даних
	char str1[size1];
	cout << "Vvedit sumvol kincia ";
	char c = cin.get();
	//повертає окремий символ
	for (int i = 0; i < 2; i++)
	{
		//cin.ignore(1, '\n'); //символ '\n' вилучається з буферу
		puts("Vvod'te strichku 1");
		cin.get(str1, size1);
		//повертає стрічку заданої довжини
		puts("\nVvedena strichka 1"); puts(str1);
		puts("\nVvod'te strichku 2");
		cin.get(str1, size1, c);
		//повертає стрічку до досягнення заданої довжини
		//або вказаного символу
		puts("\nVvedena strichka 2");
		puts(str1);
		//cin.ignore(1, c); //символ с вилучається з буферу
	}
}