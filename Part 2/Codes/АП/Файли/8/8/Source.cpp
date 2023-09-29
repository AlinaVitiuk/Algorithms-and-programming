// Для многочлена P(x), коефіцієнти якого задані у файлі, обчислити значення похідних P'(2.34), P'(7.2), P'(5.3)
#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;

int size_file(const char*);           //функція  для визначення розмірності файлу
double Derivative(double, int, int*); //функція для пошуку похідної
int main()
{
    SetConsoleOutputCP(1251);   //встановлення кодування Windows-1251 для виведення даних
    const char* file = "fn.txt"; //стрічка з іменами файлу
    int* arr = 0;            //масив, в який буде внесено вмістиме файлу
    int size;                   //розмір масиву
    double n; int i = 0;        //n - зберігає коефіцієнти, i - лічильник
    double P = 0;               //P - значення визначеного інтегралу

    size = size_file(file);     //встановлення кількості елементів у файлі
    arr = new int[size];     //виділення пам'яті під динамічний масив

    ifstream fin(file);      //відкриття файлу f.txt

    if (!fin.is_open()) {    //якщо вхідний файл не вдалося відкрити
        cout << "Вхідний файл не знайдено!";
        return 0;
    }

    while (!fin.eof()) //заповнення масиву коефіцієнтами з файлу
    {
        fin >> n;
        while (i < size)
        {
            arr[i] = n;
            i++;
            
            break;
        }

    }

    //передаємо значення ікса у функції і виводимо похідні у тих точках
    cout << "\nP'(2.34) = " << Derivative(2.34, size, arr) << endl;
    cout << "\nP'(7.2)  = " << Derivative(7.2, size, arr) << endl;
    cout << "\nP'(5.3)  = " << Derivative(5.3, size, arr) << endl;
    delete[] arr;
    return 0;
}

int size_file(const char* fn) {
    int n = 0; // n - кількість елементів у файлі
    int a; //a - цілочисельна змінна для зберігання поточного даного, зчитаного з файлу
    ifstream file;
    file.open(fn);
    while (!file.eof()) //поки не досягнуто кінця файлу
    {
        file >> a;
        n++;
    }
    file.close(); //закриття файлу
    return n; //повернення кількості елементів у файлі або -1, якщо файл порожній
}

double Derivative(double x, int size, int* arr)
{
    double der = 0;
    int size1 = size - 2;

    for (int j = size1, i = 0; j > 0, i < size; j--, i++)
    {

        der += arr[i] * (j + 1) * pow(x, j);


    }
    return der;
}
