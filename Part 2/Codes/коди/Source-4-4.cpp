#include<iostream>
#include<conio.h>
const int size1 = BUFSIZ;
using namespace std;
void main()
{
	char str[size1] = "";//������� ����� ������� ��������� BUFSIZ
	char c_end;//������ ���������� �����
	int n = size1 - 1;
	int i = 0;
	cout << "Vvedit' sumvol kincia texty : c_end = ";
	c_end = _getche();//������������ ������� ���������� �����
	_putch('\n');
	cout << "Vvod'te text\n";
	while (i < n && ((str[i] = _getche()) != c_end)) 
		i++;//������������ ��� ������
	//��� �������� '\n' ��������� CTRL+ENTER
	str[i] = '\0'; n = i;
	cout << "\n\nVvedenuj tekst maje " << (n) << " sumvoliv\n\n" << str << endl;
	cout << "\n\nPosumvolnuj nebyferuzovanuj vuvid\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '-';
		_putch(str[i]), _putch('\n');
	}
	cout << '\n';
}