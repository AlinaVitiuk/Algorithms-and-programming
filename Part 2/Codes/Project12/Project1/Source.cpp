#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int SizeOfFile(const char*);  //встановлення кількості елементів у файлі
int FromFileToArr(const char*, int*&, int&); //запис даних з файлу у масив

int main()
{
    SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних

    const char* a_name = "A.txt", * b_name = "B.txt", * c_name = "C.txt"; //стрічки з іменами файлів
    int* arr1 = 0, * arr2 = 0, * arr3 = 0; //a, b, c - імена масивів
    int sizea, sizeb, sizec; //змінні для збереження кількості елементів у файлах (розмірність масивів)
    int i = 0, j = 0, k = 0; //лічильники

    //встановлення кількості елементів у файлах
    sizea = SizeOfFile(a_name);
    sizeb = SizeOfFile(b_name);
    int n = 0; // змінна для визначення кількості елементів A\B

    //виділення пам'яті під динамічний масив
    arr3 = new int[sizea];

    //запис даних з файлів у масиви
    FromFileToArr(a_name, arr1, sizea);
    FromFileToArr(b_name, arr2, sizeb);

    //підрахунок A\B
    for (int i = 0; i < sizea; i++)
    {
        int f = 0;
        for (int j = 0; j < sizeb; j++)
            if (arr1[i] == arr2[j])
                f = 1;
        if (!f)
            if (arr3[k++] = arr1[i])
                n++;
    }

    ofstream fout(c_name); //створення нового файлу C.txt
    for (int k = 0; k < n; k++)
    {
        fout << arr3[k] << " "; //запис даних у файл
    }

    if (n > 2) {
        cout << "\nФайл ff.txt заповнено різницею елементів з файлів A.txt i B.txt\n";
    }
    else {
        cout << "\nПомилка при заповненні файлу C.txt різницею елементів з файлів A.txt i B.txt\n";
    }
    delete[] arr1, arr2, arr3; //звільнення пам'яті
    fout.close(); //закриття файлу
}

int SizeOfFile(const char* fn) {
    int n = 0; // n - кількість елементів у файлі
    int a; //змінна для зберігання зчитаного числа
    ifstream fin;
    fin.open(fn);
    while (!fin.eof()) //поки не досягнуто кінця файлу
    {
        fin >> a;
        n++;
    }
    fin.close(); //закриття файлу
    return n ? n : -1; //повернення кількості елементів у файлі або -1, якщо файл порожній
}

int FromFileToArr(const char* fn, int*& a, int& n) //запис даних з файлу у масив
{
    ifstream file;
    file.open(fn);
    n = SizeOfFile(fn); //встановлення кількості елементів у файлі
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