#include<iostream>
const int size1 = BUFSIZ;
using namespace std;
void main()
{
	char str1[size1] = "Examples";
	int i = puts("\nVuvid konstantnoi strichku ");
	cout << "Rezyltat fynkcii puts = " << i << endl;
	puts(str1);
}