//���������� ����� � ����
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char filename[20]; //������ � ������ �����
	cout << "Enter name for new file: ";
	cin.getline(filename,20);
	//��������� ��'���� ������ ������ ��� ������ ����� � ������ fout
	ofstream fout(filename); 
	fout << "For your eyes only!\n"; //����� � ����
	cout << "Enter your secret number: "; //���� �� �����
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl; //����� � ����
	fout.close(); //�������� �����
	//��������� ��'���� ������ ������ ��� ������ ����� � ������ fin
	ifstream fin(filename);
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch)) //������� ������� � �����
		cout << ch; //���� ��������� ������� �� �����
	cout << "Done\n";
	fin.close(); //�������� �����
	return 0;
}