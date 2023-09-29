//6. Для заданих невпорядкованих числових файлів f та g написати програму перетину
//цих двох файлів у третій файл ff.
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int size_file(const char*);  //встановлення кількості елементів у файлі
int from_file_to_array(const char*, int*&, int&); //запис даних з файлу у масив

int main()
{
    SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних

    const char* data1 = "f.txt", * data2 = "g.txt", * data3 = "ff.txt"; //стрічки з іменами файлів
    int* arr1 = 0, * arr2 = 0, * arr3 = 0; //a, b, c - імена масивів
    int size1, size2, size3; //змінні для збереження кількості елементів у файлах (розмірність масивів)
    int i = 0, j = 0, k = 0; //лічильники
    //встановлення кількості елементів у файлах
    size1 = size_file(data1);
    size2 = size_file(data2);
    size3 = size1 + size2;

    //виділення пам'яті під динамічний масив
    arr3 = new int[size3];

    //запис даних з файлів у масиви
    from_file_to_array(data1, arr1, size1);
    from_file_to_array(data2, arr2, size2);

    //перетин масивів
    while (i < size1 && j < size2)
    {
        for (j = 0; j < size2; j++)
        {
            for (i = 0; i < size1; i++)
            {
                if (arr2[j] == arr1[i])
                    arr3[k++] = arr2[j];
            }
        }
    }

    //cортування масиву arr3
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (arr3[i] > arr3[j]) {
                int p = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = p;
            }
        }
    }
    ofstream fout(data3); //створення нового файлу ff.txt
    for (int i = 0; i < k; fout << arr3[i++] << " ") //запис даних у файл
    
    if (size1 == 1 || size2 == 1)
    {
        cout << "\nПеревірте, будь ласка, чи заповнені вхідні файли\n";
    }
    if (k > 0) {
        cout << "\nФайл ff.txt заповнено перетином елементів з файлів f.txt i g.txt\n";
    }
    else {
        cout << "\nПомилка при заповненні файлу ff.txt перетином елементів з файлів f.txt i g.txt. Не знайдено спільних елементів для файлів f.txt i g.txt\n";
    }
    delete[] arr1, arr2, arr3; //звільнення пам'яті
    fout.close(); //закриття файлу
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

int from_file_to_array(const char* fn, int*& a, int& n) //запис даних з файлу у масив
{
    ifstream file;
    file.open(fn);
    n = size_file(fn); //встановлення кількості елементів у файлі
    a = new int[n]; //виділення пам'яті під динамічний масив
    for (int i = 0; i < n;)
    {
        file >> a[i++]; //введення усіх даних з файлу у масив
    }
    if (!file.is_open()) {
        printf("\n Файл %s не знайдено\n", fn);
    }
    file.close(); //закриття файлу
    return 1; //повернення значення "успіх"
}
