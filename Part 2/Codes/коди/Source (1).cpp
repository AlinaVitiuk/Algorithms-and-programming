/*Створити двовимірний динамічний масив символів, де кожен рядок
може мати різну розмірність, залежно від уведеної символьної стрічки
(речення).Доповнювати цей масив доти, поки не буде введено порожню
стрічку.Вивести на екран введений текст, а тоді, використовуючи вказівники,
впорядкувати його так, щоб кожна наступна стрічка була не коротшою від
попередньої.*/

#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning (disable :4996)
using namespace std;

enum 
{
    choice_Print=1, choice_Sort, choice_Quit
};

int input_number(const char*);              //введення числа
int menu();                                 //меню
char** Add_line(char**, int&, int&);        //введення тексту 
void Sort_lines(char**&, int);              //впорядкування тексту (кожен наступний рядок довший за попередній)
void Print_text(char**, int, const char*);  //вивід тексту на екран
void Delete_all_lines(char**&, int&);       //очищення всього тексту

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //зміна кодування для використання кирилиці при вводі та виводі

    char** text = 0; int n = 0, m=0, choice;
    cout << "\n\tВведіть текст\n";
    cout << "для завершення натисніть двічі ENTER\n";
    do {
        text = Add_line(text, n, m);
    } while (m != 0);
    
	while ((choice = menu()) != choice_Quit)
    {
        switch (choice)
        {
        case choice_Print: Print_text(text, n, "Текст"); break;
        case choice_Sort: Sort_lines(text, n); break;
        case choice_Quit: break;
        default:cout << "\nНевiрний вибiр\n"; break;
        };
    }
    cout << "\nКiнець програми\n";
    return 0;
}

int menu() //меню
{
    int choice;
    cout << "\n\tПодальші дії з текстом:\n"
        << choice_Print << " - друк тексту\n"
        << choice_Sort << " - впорядкування тексту (кожен наступний рядок довший за попередній)\n"        
        << choice_Quit << " - ВИХІД\n\n";
    choice = input_number("Ваш вибiр");
    return choice;
}

int input_number(const char* ms) //введення числа
{
    char rez[10];
    cout << "Введіть " << ms << " = ";
    gets_s(rez);
    return atoi(rez);
}

char** Add_line(char** a, int& n, int& m) //введення стрічки
{
    char str[BUFSIZ]; 
    gets_s(str);
    m = int(strlen(str));
    
    if (!n)
    {
        a = new char* [++n];
        a[0] = new char[m + 1];
        strcpy(*a, str);
        return a;
    }
    char** c = new char* [++n];
    for (int i = 0; i < n - 1; i++)
    {
        *(c + i) = *(a + i);
    }
    c[n - 1] = new char[m + 1];
    strcpy(*(c + n - 1), str);
    delete[]a;
    return c;
}

void Delete_all_lines(char**& a, int& n) //очищення всього тексту
{
    for (int i = 0; i < n; i++)
        delete[]a[i];
    delete[]a;
    n = 0;
}

void Print_text(char** a, int n, const char* ms) //вивід тексту на екран
{

        cout << "\n*** " << ms << " ***\n";
        for (int i = 0; i < n; i++)
            cout << *(a + i) << endl;
}

void Sort_lines(char**& a, int n) //впорядкування тексту (кожен наступний рядок довший за попередній) 
{
    int p = 1, k = n;
    while (p && k > 1)
    {
        p = 0; k--;
        for (int i = 1; i <= k; i++)
        {
            if (strlen(*(a + i - 1)) > strlen(*(a + i)))
            {
                char* b = *(a + i - 1);
                *(a + i - 1) = *(a + i);
                *(a + i) = b;
                p = 1;
            }
        }
    }
    cout << "Текст впорядковано!\n";
}

