#include<iostream>

using namespace std;

struct DATE
{
    int Day;
    int Month;
    int Year;
};

int CheckIsLeapYear(int y)// Перевірка чи рік вискосний
{
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    if (y % 4 == 0) return 1;
    return 0;
}
int DaysInMonth(int month, int year)//Checks how many days in the month
{
    static const int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && CheckIsLeapYear(year))
        return 29;

    return NumberOfDays[month - 1];
}
void AdvanceDate(int N_Days, int& day, int& m, int& y)//Calculates the date after a few days
{
    int dayofmonth = DaysInMonth(m, y);

    if (dayofmonth - day >= N_Days) {
        day += N_Days;
        return;
    }
    else {
        N_Days -= (dayofmonth - day + 1);
        day = 1;
        ++m;
    }
    while (true)
    {
        int dayofmonth = DaysInMonth(m, y);

        if (dayofmonth - day >= N_Days) {
            day += N_Days;
            break;
        }
        else
            N_Days -= (dayofmonth - day + 1);

        if (++m > 12) {
            m = 1;
            ++y;
        }
    }
}
void main()
{
    DATE DMY;
 
    int Day = 0;
    cout << "Day: ";
    cin >> DMY.Day;
    cout << "Month: ";
    int Month = 0;
    cin >> DMY.Month;
    cout << "Year: ";
    int Year = 0;
    cin >> DMY.Year;
    
    cout << "*** ANALYZING ENTERED THE DATE, SET THE DATE ON N DAYS AHEAD ***" << "\n";
    //Enter count of days
    cout << "Enter N_Days: ";
    int N_Days = 0;
    cin >> N_Days;
    //Calculates the date wich will be after entered count of dats
    AdvanceDate(N_Days, DMY.Day, DMY.Month, DMY.Year);
    cout << "After " << N_Days << " days date will be:" << DMY.Day << " " << DMY.Month << " " << DMY.Year << "\n\n";

    system("pause");
}