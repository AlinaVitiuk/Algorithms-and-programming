//Для многочлена, коефіцієнти якого задані у файлі
//f, обчислити значення визначеного інтегралу

#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;

int size_file(const char*); //встановлення кількості елементів у файлі
double integral(double, int, double*); //інтегрування

int main()
{
    SetConsoleOutputCP(1251);    //встановлення кодування Windows-1251 для виведення даних
    const char* file = "fn.txt"; //стрічка з іменами файлу
    double* arr = 0;             //масив, в який буде внесено вмістиме файлу
    int size;                    //розмір масиву
    double n; int i = 0;         //n - зберігає коефіцієнти, i - лічильник
    double P = 0;                //P - значення визначеного інтегралу

    size = size_file(file);     //встановлення кількості елементів у файлі
    arr = new double[size];     //виділення пам'яті під динамічний масив

    ifstream fin(file);      //відкриття файлу f.txt

    if (!fin.is_open()) {    //якщо вхідний файл не вдалося відкрити
        cout << "Вхідний файл не знайдено!";
        return 0;
    }

    //запис чисел і коефіцієнтів у масив
    while (!fin.eof())
    {
        fin >> n;
        while (i < size)
        {
            arr[i] = n;
            i++;
            break;
        }
    }

    P = integral(5.76, size, arr) - integral(2.34, size, arr);
    cout << "Інтеграл на відрізку [2.34; 5.76] = " << P << endl; //вивід інформації на екран

    delete[] arr;
    return 0;
}

int size_file(const char* fn) { //встановлення кількості елементів у файлі
    int size = 0; // n - кількість елементів у файлі
    double a;        //a - цілочисельна змінна для зберігання поточного даного, зчитаного з файлу
    ifstream file;
    file.open(fn);
    while (!file.eof()) //поки не досягнуто кінця файлу
    {
        file >> a;
        size++;
    }
    file.close(); //закриття файлу
    return size;  //повернення кількості елементів у файлі або -1, якщо файл порожній
}

double integral(double x, int size, double* arr) //інтегрування
{
    double p = 0; //інтеграл многочлена у заданій точці
    for (int j = size, i = 0; j > 0, i < size; j--, i++)
    {
        p += arr[i] / j * pow(x, j);
    }
    return p;
}