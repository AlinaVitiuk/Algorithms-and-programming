//Створити двовимірний динамічний масив, кожен елемент якого згенерований комп'ютером. 
//Написати функцію додавання до масиву нового стовпця із заданим номером та заповнення його відповідними даними, 
//а також функцію вилучення вибраного стовпця.
//Передбачити можливість доповнення та зменшення масиву декілька разів за вибором.
//Результати відобразити нa екран.

#include <iostream>     // бібліотека і відповідний заголовний файл
#include <Windows.h>    // підключення заголовного файлу
#include<time.h>        //заголовний файл, що містить типи і функції для роботи з датою й часом.
using namespace std;

int menu();//меню
int** Create_mtrx(int**, int&, int&);        //створення матриці
void Print_mtrx(int**, int, int);            //друк матриці
int** Insert_column(int**, int&, int&);      //додавання до масиву нового рядка
int** Delete_column(int**, int&, int&);      //вилучення вибраного рядка
bool Is_empty_array(int);                    //перевірка порожності матриці
void Delete_mtrx(int**, int&);               //видалення матриці

int main()
{
	SetConsoleOutputCP(1251); //Встановлення кодування Windows-1251 для виведення даних
	int n = 0, m = 0, choice, ** a = NULL;
	
	while ((choice = menu()) != 5)
	{
		switch (choice)  //вибір одного з пуктів меню
		{
		case 1: a = Create_mtrx(a, n, m); break;
		case 2: if (!Is_empty_array(n)) Print_mtrx(a, n, m); break;
		case 3: if (!Is_empty_array(n)) a = Insert_column(a, n, m); break;
		case 4: if (!Is_empty_array(n)) a = Delete_column(a, n, m); break;
		case 5: break;
		default: cout << "Невiрний вибiр!\n"; break;
		}
		cout << "\n\n";
	}
	if (n) Delete_mtrx(a, n);
	cout << "\nКiнець програми.\n";
}

int menu()
{
	float choice;
	cout << "\n\t\t~ МЕНЮ ~\n";
	cout << "Вибiр команди:\n\t\t";
	cout << "1 - створити матрицю\n\t\t";
	cout << "2 - друк матрицi\n\t\t";
	cout << "3 - додавання стовпця\n\t\t";
	cout << "4 - вилучення стовпця\n\t\t";
	cout << "5 - вихiд\n";
	cout << "Введiть Ваш вибiр: ";
	cin >> choice;
	return (int)choice;
}
int** Create_mtrx(int** array, int& n, int& m)//створення матриці
{
	cout << "\n\n~Створення матрицi~\n";
	do
	{
		cout << "\n\tВведiть кількість рядкiв: ";
		cin >> n;
	} while (n <= 0);
	{
		cout << "\tВведiть кількість стовпцiв: ";
		cin >> m;
	} while (m <= 0);
	array = new int* [m];
	int c = 10, d = 100;
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
		for (int j = 0; j < n; j++)
		array [i] [j] = rand() % (d - c);
	}
	cout << "\nМатрицю створено!\n";
	return array;
}

void Print_mtrx(int** array, int n, int m)//друк матриці
{
	
	int** array_t; // транспонована матриця 
	array_t = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array_t[i] = new int[m];
	}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				*(*(array_t + j) + i) = array[i][j];
			}
		}
		cout << "Матриця\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << array_t [i][j];
		}
		cout << "\n";
	}

}

int** Insert_column(int** array, int& n, int& m)//додавання до масиву нового стовпця
{
	int k, j = 0;
	do
	{
		cout << "\nУ матрицi " << m << " стовпців.\n";
		cout << "\tВведiть номер стовпців для вставки = ";
		cin >> k;
	} while (k <= 0 || k > m + 1);
	k--;
	int** new_array = new int* [++m];
	for (int i = 0; i < m; i++)
	{
		if (i == k)
		{
			new_array[i] = new int[n];
			int c = 10, d = 100;
			for (int j = 0; j < n; j++)
				*(*(new_array + i) + j) = rand() % (d - c);
			j = 1;
		}
		else *(new_array + i) = *(array + i - j);
	}
	cout << "\nСтовпець додано!\n";
	delete[]array;
	return new_array;
}

int** Delete_column(int** array, int &n, int& m)//вилучення вибраного стовпця
{
	int k, j = 0;
	do
	{
		cout << "\nУ матрицi " << m << " стовпців\n";
		cout << "\tВведiть номер стовпця для видалення = ";
		cin >> k;
	} while (k <= 0 || k > m);
	k--;
	int** new_array = new int* [--m];
	for (int i = 0; i < m; i++)
	{
		if (i == k) j = 1;
		*(new_array + i) = *(array + i + j);
	}
	cout << "\nСтовпець вилучено!\n";
	delete[]array[k];
	delete[]array;
	return new_array;
}

bool Is_empty_array(int n)//перевірка порожності матриці
{
	if (!n) cout << "\nМатриця порожня!\n";
	return (n) ? false : true;
}

void Delete_mtrx(int** array, int& n)//видалення матриці
{
	for (int i = 0; i < n; i++)
		delete[]array[i];
	delete[]array;
	n = 0;
}