//������� ���������� ����� ����� � ������ ������, �̳����� �� �г�.
//�������� �� ������������ �������, ���:
//�).�������� ��������(� ����), �� ����������� ������ ������ �� ����� �������� ������;
//�).��������� ���������� ����� ��� � ����, ������� ����� � ����� ����, �� ���������� �������� ���;
//�).��������� ������� ����, ������� ���� �� N ��� ������.
#include <iostream>
#include <ctime>
#include<Windows.h>
using namespace std;

struct Date {
    int Day;    //����
    int Month;  //�����
    int Year;   //��
};

const int secondsInDay = 60 * 60 * 24; //������ ������ � �� 

long dateInterval(const Date& startDate, const Date& endDate); //�������� ��������(� ����), �� ����������� ������ ������ �� ����� �������� ������;
Date dateFromDayOfYear(int day); //��������� ���������� ����� ��� � ����, ������� ����� � ����� ����, �� ���������� �������� ���;
int daysInMonth(int mday); // ʳ����� ��� � ����� 
Date leapAhead(const Date& sourceDate, int daysAhead); //��������� ������� ����, ������� ���� �� N ��� ������.
int EnterNumber(const char*); // �������� ��c�� 
Date EnterDate(const char*); // �������� ���� 
bool IncorrectDate(Date); // �������� ���������� ���� 

int main()
{
    SetConsoleOutputCP(1251); /* ���� ��������� ��� ������������ �������� ��� ���� �� ����� */
    SetConsoleCP(1251);
    // ����� A
    cout << "\n����� ��������� ̲� ������\n";
    Date Date_1;
    Date Date_2;
    Date_1 = EnterDate("����� ����");
    Date_2 = EnterDate("����� ����");
    auto diff = dateInterval(Date_1, Date_2);
    cout << "\n�������� �� ������:" << diff;
    cout << "\n";

    // ����� B
    cout << "\n��������� ���� �� ��������� ������� ���\n";
    int d = 0;
    do {
        d = EnterNumber("���������� ����� ��� � 2021 ����:");
    } while (d > 365);
    Date resultDate = dateFromDayOfYear(d);
    cout << "\n������ ��� ������� ����: " << resultDate.Day << "." << resultDate.Month << ".2021";
    cout << "\n";
  
    // ����� C
    cout << "\n��������� ���� �� N �Ͳ� ������\n";
    Date Date_3;
    Date_3 = EnterDate("����");
    int N;
    N = EnterNumber("���� N : ");
    Date resultDate2 = leapAhead(Date_3, N);
    cout << "\n���� � ������ N: " << resultDate2.Day << "." << resultDate2.Month << "." << resultDate2.Year;
    return 0;
}

// �������� ���� 
Date EnterDate(const char* ms) {
    Date a;
    cout << "\n\t������� " << ms << " :\n";
    do {
        a.Day = EnterNumber(" ���� ");
        a.Month = EnterNumber(" �i���� ");
        a.Year = EnterNumber("�i�");
    } while (IncorrectDate(a)); // �������� ���������� ����
    return a;
}

// ������� �� ������
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

// ����� ���� �� ���� � ����
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

// ��� � ����� 
int daysInMonth(int mday) {
    int mDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return mDays[mday % 12];
}

// ���� � ������ N
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

// �������� ���������� ������� ����
bool IncorrectDate(Date a)
{
    if (a.Month < 1 || a.Month > 12 || a.Day < 1 || a.Day > 31)
    {
        cout << "\n���������� ����\n";
        return true;
    }
    bool rez = false; /* true - ���� ���� ����������, false - ���� ���� �������� */
    switch (a.Month)
    {
    case 4: case 6: case 9: case 11: if (a.Day > 30) rez = true; break; /* �����, �� ����� �� 30 ��� */
    case 2: /* ����� ����� */
        if (a.Day > 29)
            rez = true;
        else
            rez = (a.Day == 29) && (a.Year % 4 || (a.Year % 100 == 0 && a.Year % 400)); break; /* ������������ �� */
    }
    if (rez == true)
    {
        cout << "\n���������� ����\n";
    }
    return rez;
}
// �������� ����� 
int EnterNumber(const char* ms) {
    cout << "\n������� " << ms << " = ";
    char rez[15];
    bool flag = false;
    do {
        flag = false;
        gets_s(rez);
        for (int i = 0; i < strlen(rez); i++) {
            if (!isdigit(rez[i])) { flag = true; }
        }
        if (flag == true) cout << "\n������ �������� �����: ";
    } while (flag == true);
    return atoi(rez);
}