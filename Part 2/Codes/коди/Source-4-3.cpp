#include<iostream>
using namespace std;
void main()
{
	char str1[10] = "Education";//так можна
	//char str2[3] = "may";//так НЕ можна
	char str3[] = "Initialization";//так можна
	const char* str4 = "Knowledge";//так можна
	//char *str5 = { 'H','e','l','l','o',',',' ','w','o','r','l','d','!','\0' };//так НЕ можна
	//бо str5 - це вказівник на символ, а не не масив символів
	cout << str1 << '\n'  << '\n' << str3
		<< '\n' << str4 << '\n'  << '\n';
}