//Збереження даних у файл
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char filename[20]; //стрічка з іменем файлу
	cout << "Enter name for new file: ";
	cin.getline(filename,20);
	//створення об'єкту потоку виводу для нового файлу з іменем fout
	ofstream fout(filename); 
	fout << "For your eyes only!\n"; //запис у файл
	cout << "Enter your secret number: "; //друк на екран
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl; //запис у файл
	fout.close(); //закриття файлу
	//створення об'єкту потоку виводу для нового файлу з іменем fin
	ifstream fin(filename);
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch)) //читання символу з файлу
		cout << ch; //друк зчитаного символу на екран
	cout << "Done\n";
	fin.close(); //закриття файлу
	return 0;
}