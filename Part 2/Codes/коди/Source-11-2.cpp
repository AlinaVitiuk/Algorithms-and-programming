//���������� ����� �����������
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
const char * file = "guests.txt"; //������ � ������ �����
//const char* file = "e:/ira_new/guests.txt"; //��� ������ � ������ �� �����
int main()
{
	char ch;
	// show initial contents
	ifstream fin; //��������� ��'���� ������ ����� ��� ������ ����� � ������ fin
	fin.open(file); //���������� ����� ������ � ������ file 
	if (fin.is_open()) //�������� �� �������� ����
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.get(ch)) //������� ������� � �����
			cout << ch; //���� ��������� ������� �� �����
		fin.close(); //�������� �����
	}
	//��������� ����� ����
	ofstream fout(file, ios::out | ios::app); //�������� ����� ��� ������ (���� ��� ����������)
	if (!fout.is_open()) //���� ���� �� �������
	{
		cout << "Can't open " << file << " file for output.\n";
		return 1;
	}
	cout << "Enter guest names (enter a blank line to quit):\n";
	char name[25]; //���������� ������ ��� �������� ����
	while (cin.getline(name,25) && strlen(name) > 0)
	{
		fout << name << endl;
	}
	fout.close(); //�������� �����
	//���� ����������� �����
	fin.clear(); //������� fin (�� ����'������)
	fin.open(file); //�������� ����� ��� �������
	if (fin.is_open()) //���� ���� �������
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.get(ch)) //������� ������� � �����
			cout << ch; //���� ��������� ������� �� �����
		fin.close(); //�������� �����
	}
	cout << "Done.\n";
	return 0;
}