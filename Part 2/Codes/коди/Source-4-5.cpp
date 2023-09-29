#include<iostream>//опосередковано під'єднується файл stdio.h
const int size1 = BUFSIZ;
using namespace std;
void main()
{
	char str[size1] = "";
	char c_end;
	int n = size1 - 1; int i = 0;
	cout << "Vvedit' sumvol kincia texty : c_end = ";
	c_end = getchar();//після введення символа слід натиснути на ENTER
	cout << "\nVvod'te text \n";
	//символ завершення рядка залишається у буфері!
	while (i < n && ((str[i] = getchar()) != c_end))i++;
	str[i] = '\0'; n = i;
	cout << "\nVvedenuj tekst maje " << (n)
		<< " sumvoliv\n" << str << endl;
	cout << "\nPosumvolnuj buferuzovanuj vuvid\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '-'; putchar(str[i]), putchar('\n');
	}
	cout << "\n";
}