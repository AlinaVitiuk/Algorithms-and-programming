#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning (disable :4996)

using namespace std;

void print_str(char**, int);
char** insert_line(char**, int&, int&);
void sort_lines(char**, int);


int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    int len = 0, n = 0; // len - довжина стрічки, n - кількість стрічок в масиві
    char** array = 0;

    cout << "Введіть ваш текст(для завершення пропустіть через ENTER пусту стрічку):\n";
    do {
        array = insert_line(array, n, len);
    } while (len != 0);

    if (n != 0) { // перевірка на випадок чи не пустий масив
        cout << "\nВведені стрічки:\n";
        print_str(array, n);
        cout << "\nВідсортовані стрічки:\n";
        sort_lines(array, n);
        print_str(array, n);

        for (int i = 0; i < n; i++) { // видалення динамічної пам'яті
            delete[]array[i];
        }
        delete[]array;
    }
    else { // видалення на випадок, якщо стрічки не ввелися
        cout << "\nСтрічки не введені\n";
        delete[]array;
    }
    return 0;
}

void print_str(char** arr, int n) { // функція виводу
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << endl;
}

char** insert_line(char** arr, int& n, int& len) { // функція вставки нової стрічки
    char str[BUFSIZ];
    gets_s(str);
    len = int(strlen(str)); // знаходження довжини стрічки

    if (len != 0) { // перевірка на випадок, якщо стрічка пуста
        char** lines = new char* [++n];
        for (int i = 0; i < n; i++) {
            *(lines + i) = new char[len + 1];
            if (i == n - 1) strcpy(*(lines + i), str); // доповнення нової стрічки
            else *(lines + i) = *(arr + i); // заповнення нового масиву старою стрічкою
        }
        return lines;
    }
    else {
        return arr;
    }
}

void sort_lines(char** arr, int n) { // впорядкування стрічок(кожна наступна не коротша від попередньої)
    int k = n;
    bool flag = true;
    while (flag && k > 1) { // метод Неймана
        flag = false;
        k--;
        for (int i = 0; i < k; i++) {
            if (strlen(*(arr + i)) > strlen(*(arr + i + 1))) { // заміна місцями, якщо попередня стрічка є довшою
                char* temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                flag = true;
            }
        }
    }
}