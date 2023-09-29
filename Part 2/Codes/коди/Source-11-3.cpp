//���-���� � �������� ����
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//��������� �������
inline void eatline() { while (cin.get() != '\n') continue; }
struct planet
{
	char name[20]; //����� �������
	double population; //���������
	double g; //����������� ������� ������
};
const char * file = "planets.dat"; //������ � ������ ����� 1
int main()
{
	planet pl; //����� ���� ���������
	cout << fixed << right;
	//���� ��������� �����
	ifstream fin; //��������� ��'���� ������ ����� ��� ������ ����� � ������ fin
	fin.open(file, ios_base::in | ios_base::binary); //�������� ��������� ����� ��� �������
	if (fin.is_open()) //���� ���� �������
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl)) //������� ���� �������� � ����� � ����� pl
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl; //���� ����� �� �����
		}
		fin.close(); //�������� �����
	}
	//��������� ����� ����� �� �����
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	//��������� ��'���� ������ ������ (����������) ��� ��������� ����� � ������ fout
	if (!fout.is_open()) //���� ���� �� �������
	{
		cout << "Can't open " << file << " file for output:\n";
		return 1;
	}
	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(pl.name, 20); //�������� ������ ���� �������
	while (pl.name[0] != '\0') //���� �� ������� ������ ������ �����
	{
		eatline(); //������ ������ ������ �����
		cout << "Enter planetary population: ";
		cin >> pl.population; //�������� ���������
		cout << "Enter planet's acceleration of gravity: ";
		cin >> pl.g; //�������� �����������
		eatline();
		fout.write((char *)&pl, sizeof pl); //����� � ���� ���� ������� ���������
		cout << "Enter planet name (enter a blank line "
			"to quit):\n";
		cin.get(pl.name, 20); //�������� ������ ���� �������
	}
	fout.close(); //�������� �����
	//���� ����������� �����
	fin.clear(); //������� fin (�� ����'������, ��� �� ��������)
	fin.open(file, ios_base::in | ios_base::binary); //�������� ��������� ����� ��� �������
	if (fin.is_open()) //���� ���� �������
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl)) //������� ���� �������� � ����� � ����� pl
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl; //���� ����� �� �����
		}
		fin.close(); //�������� �����
	}
	cout << "Done.\n";
	return 0;
}