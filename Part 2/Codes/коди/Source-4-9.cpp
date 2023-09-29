#include<iostream>
//#include<stdio.h>
#pragma warning(disable :4996)
const int size1 = 10;
using namespace std;
void main()
{
	char str1[size1];
	puts("Vvod'testrichku"); fgets(str1, size1, stdin);
	puts("\n Vvedena strichka"); puts(str1);
}