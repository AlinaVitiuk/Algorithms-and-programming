//Для заданих впорядкованих числових файлів A та B написати програму знаходження
//різниці цих двох файлів(A\B) і записати результат у третій файл С.

#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int size_file(const char*);  //встановлення кількості елементів у файлі
int from_file_to_array(const char*, int*&, int&); //запис даних з файлу у масив

int main()
{
    SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних

    const char* data1 = "A.txt", * data2 = "B.txt", * data3 = "C.txt"; //стрічки з іменами файлів
    int* arr1 = 0, * arr2 = 0, * arr3 = 0; //arr1, arr2, arr3 - імена масивів
    int size1, size2, size3; //змінні для збереження кількості елементів у файлах (розмірність масивів)
    int i = 0, j = 0, k = 0; //лічильники
    
    //встановлення кількості елементів у файлах
    size1 = size_file(data1);
    size2 = size_file(data2);
    int n = 0; // змінна для визначення кількості елементів A\B

    //виділення пам'яті під динамічний масив
    arr3 = new int[size1];

    //запис даних з файлів у масиви
    from_file_to_array(data1, arr1, size1);
    from_file_to_array(data2, arr2, size2);

    //підрахунок A\B
    for (int i = 0; i < size1; i++) {
        int f = 0;
        for (int j = 0; j < size2; j++)
            if (arr1[i] == arr2[j])
                f = 1;
        if (!f)
            if (arr3[k++] = arr1[i])
                n++;
    }
    
    ofstream fout(data3); //створення нового файлу C.txt
    for (int k = 0; k < n; k++) {
        fout << arr3[k] << " "; //запис даних у файл
    }
    
    if (n > 0) {
        cout << "\nФайл C.txt заповнено різницею елементів з файлів A.txt i B.txt\n";
    }
    else {
        cout << "\nПомилка при заповненні файлу C.txt різницею елементів з файлів A.txt i B.txt\n";
    }

    delete[] arr1, arr2, arr3; //звільнення пам'яті
    fout.close();              //закриття файлу
}

int size_file(const char* fn) { //встановлення кількості елементів у файлі
    int n = 0; // n - кількість елементів у файлі
    int a;     //a - цілочисельна змінна для зберігання потосного даного, зчитаного з файлу
    ifstream file;
    file.open(fn);
    while (!file.eof()) //поки не досягнуто кінця файлу
    {
        file >> a;
        n++;
    }
    file.close();      //закриття файлу
    return n ? n : -1; //повернення кількості елементів у файлі або -1, якщо файл порожній
}

int from_file_to_array(const char* fn, int*& a, int& n) { //запис даних з файлу у масив

    ifstream file;
    file.open(fn);
    n = size_file(fn); //встановлення кількості елементів у файлі
    a = new int[n];    //виділення пам'яті під динамічний масив
    for (int i = 0; i < n;)
    {
        file >> a[i++]; //введення усіх даних з файлу у масив
    }
    if (!file.is_open()) {
        printf("\n Файл %s не знайдено\n", fn);
    }
    file.close(); //закриття файлу
    return 1;     //повернення значення "успіх"
}