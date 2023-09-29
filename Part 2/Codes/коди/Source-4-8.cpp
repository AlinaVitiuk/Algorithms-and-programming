#include<iostream>
const int size1 = BUFSIZ;
using namespace std;
void main()
{
	char str1[size1];
	puts("Vvod'te strichku");
	gets_s(str1);
	//розмір стрічки str1 повинен бути
	//достатнім для запису введеної інформації
	puts("\n Vvedena strichka");
	puts(str1);
}