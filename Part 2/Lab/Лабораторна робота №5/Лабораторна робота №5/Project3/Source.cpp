//Описати структурну змінну «Дата» з полями «Число», «Місяць» та «Рік».
//Написати та протестувати функцію, яка:
//А).Обчислює інтервал(в днях), що характеризує часову віддаль між обома заданими датами;
//Б).Аналізуючи порядковий номер дня в році, визначає число і місяць року, які відповідають заданому дню;
//В).Аналізуючи введену дату, визначає дату на N днів вперед.
#include <iostream>
#include <ctime>
#include<Windows.h>
using namespace std;

struct Date {
    int Day;    //день
    int Month;  //місяць
    int Year;   //рік
};

const int secondsInDay = 60 * 60 * 24; //кількісь секунд в дні 

long dateInterval(const Date& startDate, const Date& endDate); //Обчислює інтервал(в днях), що характеризує часову віддаль між обома заданими датами;
Date dateFromDayOfYear(int day); //Аналізуючи порядковий номер дня в році, визначає число і місяць року, які відповідають заданому дню;
int daysInMonth(int mday); // Кілкість днів у місяці 
Date leapAhead(const Date& sourceDate, int daysAhead); //Аналізуючи введену дату, визначає дату на N днів вперед.
int EnterNumber(const char*); // введення чиcла 
Date EnterDate(const char*); // введення дати 
bool IncorrectDate(Date); // перевірка коректності дати 

int main()
{
    SetConsoleOutputCP(1251); /* зміна кодування для використання кирилиці при вводі та виводі */
    SetConsoleCP(1251);
    // пункт A
    cout << "\nПОШУК ІНТЕРВАЛУ МІЖ ДАТАМИ\n";
    Date Date_1;
    Date Date_2;
    Date_1 = EnterDate("першу дату");
    Date_2 = EnterDate("другу дату");
    auto diff = dateInterval(Date_1, Date_2);
    cout << "\nІнтервал між датами:" << diff;
    cout << "\n";

    // пункт B
    cout << "\nВИЗНАЧИТИ ДАТУ ЗА ПРЯДКОВИМ НОМЕРОМ ДНЯ\n";
    int d = 0;
    do {
        d = EnterNumber("порядковий номер дня в 2021 році:");
    } while (d > 365);
    Date resultDate = dateFromDayOfYear(d);
    cout << "\nДаному дню відповідає дата: " << resultDate.Day << "." << resultDate.Month << ".2021";
    cout << "\n";
  
    // пункт C
    cout << "\nВИЗНАЧИТИ ДАТУ НА N ДНІВ ВПЕРЕД\n";
    Date Date_3;
    Date_3 = EnterDate("дату");
    int N;
    N = EnterNumber("крок N : ");
    Date resultDate2 = leapAhead(Date_3, N);
    cout << "\nДата з кроком N: " << resultDate2.Day << "." << resultDate2.Month << "." << resultDate2.Year;
    return 0;
}

// введення дати 
Date EnterDate(const char* ms) {
    Date a;
    cout << "\n\tВводьте " << ms << " :\n";
    do {
        a.Day = EnterNumber(" день ");
        a.Month = EnterNumber(" мiсяць ");
        a.Year = EnterNumber("рiк");
    } while (IncorrectDate(a)); // перевірка коректності дати
    return a;
}

// ітервал між датами
long dateInterval(const Date& Date_1, const Date& Date_2) {

    struct tm tm_1;
    tm_1.tm_min = 0;
    tm_1.tm_hour = 0;
    tm_1.tm_sec = 0;
    tm_1.tm_year = Date_1.Year - 1900;
    tm_1.tm_mon = Date_1.Month - 1;
    tm_1.tm_mday = Date_1.Day;
    time_t t_1 = mktime(&tm_1);

    struct tm tm_2;
    tm_2.tm_min = 0;
    tm_2.tm_hour = 0;
    tm_2.tm_sec = 0;
    tm_2.tm_year = Date_2.Year - 1900;
    tm_2.tm_mon = Date_2.Month - 1;
    tm_2.tm_mday = Date_2.Day;
    time_t t_2 = mktime(&tm_2);

    long differenceInSeconds = t_2 - t_1;
    differenceInSeconds / secondsInDay;
    return differenceInSeconds / secondsInDay;
}

// пошук дати за днем в році
Date dateFromDayOfYear(int d) {
    Date resDate;
    int dayOfTheYear = d;
    int month = 1;
    int days = 0;
    while (dayOfTheYear > 0) {
        days += daysInMonth(month);
        dayOfTheYear = d - days;
        month++;
    }
    resDate.Day = d - days + daysInMonth(month - 1);
    resDate.Month = month - 1;
    resDate.Year = 0;
    return resDate;
}

// днів в місяці 
int daysInMonth(int mday) {
    int mDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return mDays[mday % 12];
}

// дата з кроком N
Date leapAhead(const Date& Date_3, int N) {
    Date date = Date_3;
    date.Day += N;
    int month = date.Month;

    while (date.Day > daysInMonth(month - 1)) {
        date.Day -= daysInMonth(month + 1);
        month++;
    }
    date.Month = month;
    while (date.Month > 12) {
        date.Month -= 12;
        date.Year++;
    }
    return date;
}

// перевірка коректності введеної дати
bool IncorrectDate(Date a)
{
    if (a.Month < 1 || a.Month > 12 || a.Day < 1 || a.Day > 31)
    {
        cout << "\nНекоректна дата\n";
        return true;
    }
    bool rez = false; /* true - якщо дата некоректна, false - якщо дата коректна */
    switch (a.Month)
    {
    case 4: case 6: case 9: case 11: if (a.Day > 30) rez = true; break; /* місяці, які мають по 30 днів */
    case 2: /* місяць лютий */
        if (a.Day > 29)
            rez = true;
        else
            rez = (a.Day == 29) && (a.Year % 4 || (a.Year % 100 == 0 && a.Year % 400)); break; /* невисокосний рік */
    }
    if (rez == true)
    {
        cout << "\nНекоректна дата\n";
    }
    return rez;
}
// введення числа 
int EnterNumber(const char* ms) {
    cout << "\nВводьте " << ms << " = ";
    char rez[15];
    bool flag = false;
    do {
        flag = false;
        gets_s(rez);
        for (int i = 0; i < strlen(rez); i++) {
            if (!isdigit(rez[i])) { flag = true; }
        }
        if (flag == true) cout << "\nВведіть коректне число: ";
    } while (flag == true);
    return atoi(rez);
}