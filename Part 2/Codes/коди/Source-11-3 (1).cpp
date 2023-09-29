//Ввід-вивід у двійковий файл
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//вбудована функція
inline void eatline() { while (cin.get() != '\n') continue; }
struct planet
{
	char name[20]; //назва планети
	double population; //населення
	double g; //прискорення вільного падіння
};
const char * file = "planets.dat"; //стрічка з іменем файлу 1
int main()
{
	planet pl; //змінна типу структура
	cout << fixed << right;
	//друк вмістимого файлу
	ifstream fin; //створення об'єкту потоку вводу для нового файлу з іменем fin
	fin.open(file, ios_base::in | ios_base::binary); //відкриття двійкового файлу для читання
	if (fin.is_open()) //якщо файл відкрито
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl)) //читання цілої струтури з файлу у змінну pl
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl; //друк даних на екран
		}
		fin.close(); //закриття файлу
	}
	//додавання нових даних до файлу
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	//створення об'єкту потоку виводу (доповнення) для двійкового файлу з іменем fout
	if (!fout.is_open()) //якщо файл НЕ відкрито
	{
		cout << "Can't open " << file << " file for output:\n";
		return 1;
	}
	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(pl.name, 20); //введення нового імені планети
	while (pl.name[0] != '\0') //якщо НЕ введено символ нового рядка
	{
		eatline(); //ігнорує символ нового рядка
		cout << "Enter planetary population: ";
		cin >> pl.population; //введення населення
		cout << "Enter planet's acceleration of gravity: ";
		cin >> pl.g; //введення прискорення
		eatline();
		fout.write((char *)&pl, sizeof pl); //запис у файл цілої введеної структури
		cout << "Enter planet name (enter a blank line "
			"to quit):\n";
		cin.get(pl.name, 20); //введення нового імені планети
	}
	fout.close(); //закриття файлу
	//друк доповненого файлу
	fin.clear(); //скинути fin (не обов'язково, але не завадить)
	fin.open(file, ios_base::in | ios_base::binary); //відкриття двійкового файлу для читання
	if (fin.is_open()) //якщо файл відкрито
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl)) //читання цілої струтури з файлу у змінну pl
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl; //друк даних на екран
		}
		fin.close(); //закриття файлу
	}
	cout << "Done.\n";
	return 0;
}