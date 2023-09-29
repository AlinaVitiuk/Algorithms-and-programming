#include<iostream>
const int size1 = BUFSIZ;
using namespace std;
void main()
{
	char str1[size1];
	puts("Vvod'te strichku");
	cin >> str1;
	//стрічка заповниться символами до розділювача
	cout << "\n\n VVedena strichka\n";
	puts(str1);
	//решта символів після розділювача залишається у буфері
}