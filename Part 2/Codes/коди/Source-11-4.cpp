//Довільний доступ у двійкових файлах
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int LIM = 20;
struct planet
{
	char name[LIM]; // назва планети
	double population; // населення
	double g; //прискорення вільного падіння
};
const char * file = "planets.dat"; //стрічка з іменем файлу (файл повинен існувати!)
inline void eatline() { while (cin.get() != '\n') continue; } //вбудована функція
int main()
{
	planet pl; //змінна типу структура
	cout << fixed;
	//друк вмістимого файлу
	fstream finout; //потоки для вводу і виводу
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	//відкриття двійкового файлу для читання і запису
	int ct = 0;
	if (finout.is_open()) //якщо файл відкрито
	{
		finout.seekg(0); //встановити курсор на початок файлу
		cout << "Here are the current contents of the "	<< file << " file:\n";
		while (finout.read((char *)&pl, sizeof pl)) //читання цілої струтури з файлу у змінну pl
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl; //друк даних на екран
		}
		if (finout.eof()) //якщо досягнуто кінця файлу
			finout.clear(); //очистити прапорець eof
		else //якщо НЕ досягнуто кінця файлу
		{
			cout << "Error in reading " << file << ".\n";
			return 1;
		}
	}
	else //якщо файл НЕ відкрито
	{
		cout << file << " could not be opened -- bye.\n";
		return 1;
	}
	// зміна запису у файлі
	cout << "Enter the record number you wish to change: ";
	long rec;
	cin >> rec; //номер запису у файлі, який буде змінюватися
	eatline(); //ігнорує символ нового рядка
	if (rec < 0 || rec >= ct) //перевірка коректності rec
	{
		cerr << "Invalid record number -- bye\n";
		return 1;
	}
	streampos place = rec * sizeof pl; //перетворення до типу streampos - позиція у потоці
	finout.seekg(place); //встановлення курсору у задану позицію
	if (finout.fail()) //якщо спроба відкрити файл НЕ вдалася
	{
		cerr << "Error on attempted seek\n";
		return 1;
	}
	finout.read((char *)&pl, sizeof pl); //читання заданої струтури з файлу у змінну pl
	cout << "Your selection:\n";
	cout << rec << ": " << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl; //друк заданої струтури на екран
	if (finout.eof()) //якщо досягнуто кінця файлу
		finout.clear(); // очистити прапорець eof
	cout << "Enter planet name: "; //введення оновлених даних
	cin.get(pl.name, LIM);
	eatline();
	cout << "Enter planetary population: ";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> pl.g;
	finout.seekp(place); //встановлення курсору назад у задану позицію
	finout.write((char *)&pl, sizeof pl) << flush; //виштовхує буфер виводу у файл
	if (finout.fail()) //якщо спроба записати у файл НЕ вдалася
	{
		cerr << "Error on attempted write\n";
		return 1;
	}
	//друк оновленого файлу
	ct = 0;
	finout.seekg(0); //встановити курсор на початок файлу
	cout << "Here are the new contents of the " << file
		<< " file:\n";
	while (finout.read((char *)&pl, sizeof pl)) //читання однієї струтури з файлу у змінну pl
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl; //друк даних на екран
	}
	finout.close(); //закриття файлу
	cout << "Done.\n";
	return 0;
}