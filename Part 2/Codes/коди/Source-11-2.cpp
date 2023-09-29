//Доповнення файлу інформацією
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
const char * file = "guests.txt"; //стрічка з іменем файлу
//const char* file = "e:/ira_new/guests.txt"; //або стрічка зі шляхом до файлу
int main()
{
	char ch;
	// show initial contents
	ifstream fin; //створення об'єкту потоку вводу для нового файлу з іменем fin
	fin.open(file); //звязування цього потоку з файлом file 
	if (fin.is_open()) //перевірка чи відкритий файл
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.get(ch)) //читання символу з файлу
			cout << ch; //друк зчитаного символу на екран
		fin.close(); //закриття файлу
	}
	//додавання нових імен
	ofstream fout(file, ios::out | ios::app); //відкриття файлу для запису (лише для доповнення)
	if (!fout.is_open()) //якщо файл НЕ відкрито
	{
		cout << "Can't open " << file << " file for output.\n";
		return 1;
	}
	cout << "Enter guest names (enter a blank line to quit):\n";
	char name[25]; //оголошення стрічки для введення імені
	while (cin.getline(name,25) && strlen(name) > 0)
	{
		fout << name << endl;
	}
	fout.close(); //закриття файлу
	//друк доповненого файлу
	fin.clear(); //скинути fin (не обов'язково)
	fin.open(file); //відкриття файлу для читання
	if (fin.is_open()) //якщо файл відкрито
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.get(ch)) //читання символу з файлу
			cout << ch; //друк зчитаного символу на екран
		fin.close(); //закриття файлу
	}
	cout << "Done.\n";
	return 0;
}