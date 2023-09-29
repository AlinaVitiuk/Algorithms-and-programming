//У заданому числовому файлі f з невідомим числом елементів встановити координати
//найбільшого та найменшого елементів.
#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>
using namespace std;


int size_file(const char*); //функція  для визначення розмірності файлу

int main()
{
    SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних

    const char* file = "f.txt"; //стрічка з іменем файлу
    int size;                   //кількість елементів у файлі
    int n;                      //змінна для читання вмістимого файлу
    int max, min;               //найбільший та найменший елементи
    //int max_i, min_i;           //координати найбільшого та найменшого елементів
    int i = 0;                  //лічильник
    int k = 1;                  //координати
    ifstream fin(file); //відкриття файлу f.txt
    if (!fin.is_open()) //перевірка чи відкритий файл
    {
        cout << "Вхідний файл f.txt не знайдено!";
        return 0;
    }
    
    size = size_file(file); //кількість елементів у файлі

    fin >> n; //зчитування елементів з файлів
    max = min = n;

    while (!fin.eof()) //пошук max i min
    {
        fin >> n;
        while (i < size)
        {
            if (n > max) {
                max = n;
            }
            if (n < min) {
                min = n;
            }
            i++;
            break;
        }
    }
   
    fin.close();    //закриття потоку вводу - виводу
    fin.open(file); //відкриття файлу f.txt
   
    while (!fin.eof()) //пошук координат
    {
        fin >> n;
        while (k <= size)
        {
            if (n == max) {
                cout << "\nНайбільший елемент у файлі << " << max << " >> займає " << k << " позицію\n";
            }
            if (n == min) {
                cout << "\nНайменший елемент у файлі << " << min << " >> займає " << k << " позицію\n";
            }
            k++;
            break;

        }

    }
    fin.close(); //закриття потоку вводу - виводу
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
    return n ? n : -1; //повернення кількості елементів у файлі або -1, якщо файл порожній
}
