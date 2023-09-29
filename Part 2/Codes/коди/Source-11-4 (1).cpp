//�������� ������ � �������� ������
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int LIM = 20;
struct planet
{
	char name[LIM]; // ����� �������
	double population; // ���������
	double g; //����������� ������� ������
};
const char * file = "planets.dat"; //������ � ������ ����� (���� ������� ��������!)
inline void eatline() { while (cin.get() != '\n') continue; } //��������� �������
int main()
{
	planet pl; //����� ���� ���������
	cout << fixed;
	//���� ��������� �����
	fstream finout; //������ ��� ����� � ������
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	//�������� ��������� ����� ��� ������� � ������
	int ct = 0;
	if (finout.is_open()) //���� ���� �������
	{
		finout.seekg(0); //���������� ������ �� ������� �����
		cout << "Here are the current contents of the "	<< file << " file:\n";
		while (finout.read((char *)&pl, sizeof pl)) //������� ���� �������� � ����� � ����� pl
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl; //���� ����� �� �����
		}
		if (finout.eof()) //���� ��������� ���� �����
			finout.clear(); //�������� ��������� eof
		else //���� �� ��������� ���� �����
		{
			cout << "Error in reading " << file << ".\n";
			return 1;
		}
	}
	else //���� ���� �� �������
	{
		cout << file << " could not be opened -- bye.\n";
		return 1;
	}
	// ���� ������ � ����
	cout << "Enter the record number you wish to change: ";
	long rec;
	cin >> rec; //����� ������ � ����, ���� ���� ����������
	eatline(); //������ ������ ������ �����
	if (rec < 0 || rec >= ct) //�������� ���������� rec
	{
		cerr << "Invalid record number -- bye\n";
		return 1;
	}
	streampos place = rec * sizeof pl; //������������ �� ���� streampos - ������� � ������
	finout.seekg(place); //������������ ������� � ������ �������
	if (finout.fail()) //���� ������ ������� ���� �� �������
	{
		cerr << "Error on attempted seek\n";
		return 1;
	}
	finout.read((char *)&pl, sizeof pl); //������� ������ �������� � ����� � ����� pl
	cout << "Your selection:\n";
	cout << rec << ": " << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl; //���� ������ �������� �� �����
	if (finout.eof()) //���� ��������� ���� �����
		finout.clear(); // �������� ��������� eof
	cout << "Enter planet name: "; //�������� ��������� �����
	cin.get(pl.name, LIM);
	eatline();
	cout << "Enter planetary population: ";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> pl.g;
	finout.seekp(place); //������������ ������� ����� � ������ �������
	finout.write((char *)&pl, sizeof pl) << flush; //�������� ����� ������ � ����
	if (finout.fail()) //���� ������ �������� � ���� �� �������
	{
		cerr << "Error on attempted write\n";
		return 1;
	}
	//���� ���������� �����
	ct = 0;
	finout.seekg(0); //���������� ������ �� ������� �����
	cout << "Here are the new contents of the " << file
		<< " file:\n";
	while (finout.read((char *)&pl, sizeof pl)) //������� ���� �������� � ����� � ����� pl
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl; //���� ����� �� �����
	}
	finout.close(); //�������� �����
	cout << "Done.\n";
	return 0;
}