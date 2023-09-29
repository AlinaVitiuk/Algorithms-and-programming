#include<iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

struct Date
{
    int day;
    int mon;
    int year;
};

//����� ���������� � 0-�� ��� ��������
//0 - ������ 11 - �������
int month_len[] = {31,28,31,30,31,30,31,31,30,31,30,31};

char* getTextDate(Date pst);
//���� ����
bool EnterDate(Date& pst);
//�������� ������������ ����
 
//�������� ���� �� �����������
bool CheckLongYear(int year);
//������������ �������� - ������ � ��������� �������� ����

bool CheckDate(Date pst);
//���������� ����, ��������� � ������ ����
long getDaysFromYearBeg(Date pst);
//��������� ��������� ��� pst1 � pst2
bool EqualDate(Date pst1, Date pst2);
//��������� ������ �� ���� pst1 ��� pst1
bool CompDate(Date pst1, Date pst2);
//������� ����� ����������� ������ �����
//���� �� ����� ����������������� ����
Date EnterDate();
//������� ��������� ���� �������� �� ������ �� ����� ���� nDays
Date getDateWithDiference(Date pst, long nDays);
//���������� ����� ���� ����� 2-�� ������
long getDaysAmongDates(Date pst1, Date pst2);
//��������� ��������� ���������� ���� �� ���������� ��������� ���
Date getRandDate(int min_year, int max_year);
//���������� �������� pst1 � pst2
void SwapDate(Date& pst1, Date& pst2);

//������� ����������� ������� ����
void p1();
void p2();
void p3();
//������ ������� �������� �� ������������ ��������� ������ 
//�� ������ ptr (����� ����� ��� ��� ������ ����� ���� �������� � 
//��� ��������� bad_alloc, �� ����� �� ���� �������)
template <class T>
T* alloc_mem(T* ptr, unsigned long count);

int main()
{
	//���� ��������� ��� ������������ �������� ��� ���� �� ����� 
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
    while (true)
    {
        system("cls");
        cout << "\t***MENU***\n";
        cout << "1 - ��� �������� ������� ����, � ������������ �����;\n";
        cout << "2 - ����, �������� ������� � �������� ���� D\n";
        cout << "    � ��������� ���� ��� � ������ ���� �� ����,\n";
        cout << "    ��������� �� ��������� �� 15k ����\n";
        cout << "3 - ����� ���� � ������� �� ����� ����\n";
        //��� ������� �� �������� getch �� ������� ������ ���� - ��� ���� ��� ����
        switch (getch() - '0')
        {
        case 1:
            p1();
            break;
        case 2:
            p2();
            break;
        case 3:
            p3();
            break;
        }
        system("pause");
    }
    return 0;
}

template <class T>
T* alloc_mem(T* ptr, unsigned long count)
{
    try
    {
        ptr = new T[count];
    }
    catch (bad_alloc& e)
    {
        cout << e.what() << "\n";
        ptr = NULL;
    }
    return ptr;
}

void p1()
{
    srand(time(NULL));
    unsigned int i, j, N;
    char sDate[12] = { 0 };
    Date* array = NULL;

    cout << "������� N : ";
    if (!(cin >> N))
        cout << "������ �����\n";
    else
        if (!(array = alloc_mem(array, N + 1)))
            cout << "������ ��������� ������ ��� ������ ���\n";
        else
        {
            array[0] = EnterDate();
            cout << "������ ���������������� ���\n";
            for (i = 1; i <= N; i++)
            {
                //���������� ��������� ������� ������ ���
                array[i] = getRandDate(-100, 2100);
                if (!strcpy(sDate, getTextDate(array[i])))
                    cout << "������ ������ ���������� �������� ����\n";
                else
                    cout << sDate << endl;
            }
            //����� ������� 3 ������� ����
            //����������� ��� ������ �� ��������
            //����� ������ ���� ����� �������� ��������
            for (i = 1; i <= N; i++)
                for (j = i + 1; j <= N; j++)
                {
                    if (CompDate(array[i], array[j]))
                        SwapDate(array[i], array[j]);
                }
            cout << "�������� ������� ���� � ������������ �����\n";
            for (i = 1; i <= N; i++)
            {
                if (!strcpy(sDate, getTextDate(array[i])))
                    cout << "������ ������ ���������� �������� ����\n";
                else
                    cout << sDate << endl;
            }
            delete[] array;//������ ������
        }
}

void p2()
{
    long k;
    char sDate[12] = { 0 };
    Date pst = EnterDate();
    Date buf = pst;
    int year = pst.year;
    for (k = 1; buf.year == year; k++)
    {
        buf = getDateWithDiference(pst, 15 * k);
        if (!strcpy(sDate, getTextDate(buf)))
            cout << "������ ������ ���������� �������� ����\n";
        else
            cout << sDate << endl;
    }
}

void p3()
{
    char sDate[12] = { 0 };
    Date pst = EnterDate();
    if (!strcpy(sDate, getTextDate(pst)))
        cout << "������ ������ ���������� �������� ����\n";
    else
        cout << sDate << endl;
}

//�������� ���� �� �����������
bool CheckLongYear(int year)
{
    bool bLong = false;
    if (year % 4 == 0)
        bLong = true;
    return bLong;
}

char* getTextDate(Date pst)
{
    char sDate[16] = { 0 };
    if (!sprintf(sDate, "%02d %03s %d", pst.day, month_name[pst.mon - 1], pst.year))
        sprintf(sDate, "%s", "format error");
    return &sDate[0];
}

//���� ����
bool EnterDate(Date& pst)
{
    bool bCorrect = true;
    if ((cout << "Enter year : ") && !(cin >> pst.year))
        bCorrect = false;
    if ((cout << "Enter month: ") && !(cin >> pst.mon))
        bCorrect = false;
    if ((cout << "Enter day  : ") && !(cin >> pst.day))
        bCorrect = false;
    return bCorrect;
}

//�������� ������������ ����
bool CheckDate(Date pst)
{
    //�.� ���������� ��� � �������
    int addDays = (CheckLongYear(pst.year) && pst.mon == 1) ? 1 : 0;
    bool bCorrect = true;
    if (pst.mon < 1 || 12 < pst.mon)
        bCorrect = false;
    else
        if (!pst.day || (month_len[pst.mon - 1] + addDays < pst.day))
            bCorrect = false;
    return bCorrect;
}

//������� ����� ����������� ������ �����
//���� �� ����� ����������������� ����
Date EnterDate()
{
    Date pst = { 0 };
    //����� ��������� � ����� ���� �� ���� �� ����� ���� ����
    while (true)
    {
        //���� �������� ���� ����� � 0 ��������
        cout << "������� �������� ����\n";
        if (!EnterDate(pst))
            cout << "������ �����\n";
        else
            if (!CheckDate(pst))
                cout << "������� ������������ ����\n";
            else
                break;
    }
    return pst;
}

//���������� ����, ��������� � ������ ����
long getDaysFromYearBeg(Date pst)
{
    long nDays = 0;
    bool isLongYear = CheckLongYear(pst.year);
    for (int i = 1; i < pst.mon; i++)
    {
        if (i == 2 && isLongYear)
            nDays += 1;
        nDays += month_len[i - 1];
    }
    nDays += pst.day;
    return nDays;
}
//��������� ��������� ��� pst1 � pst2
bool EqualDate(Date pst1, Date pst2)
{
    bool bEqual = true;
    if (pst1.year != pst2.year)
        bEqual = false;
    else
        if (pst1.mon != pst2.mon)
            bEqual = false;
        else
            if (pst1.day != pst2.day)
                bEqual = false;
    return bEqual;
}

//��������� ������ �� ���� pst1 ��� pst1
bool CompDate(Date pst1, Date pst2)
{
    bool bGreather = true;
    if (pst2.year < pst1.year)
        bGreather = false;
    else
        if (pst2.mon < pst1.mon && pst1.year == pst2.year)
            bGreather = false;
        else
            if (pst2.day < pst1.day && pst1.mon == pst2.mon)
                bGreather = false;
    return bGreather;
}

//������� ��������� ���� �������� �� ������ �� ����� ���� nDays
Date getDateWithDiference(Date pst, long nDays)
{
    if (nDays < pst.day)
        pst.day -= nDays;
    else//����� ��������� �� ������� � ����� ���� �� ��������� ���
    {
        nDays -= pst.day;
        for (pst.mon -= 1; 0 < nDays; pst.mon--)
        {
            if (pst.mon < 1)
            {
                pst.mon = 12;
                pst.year--;
            }
            nDays -= month_len[pst.mon - 1];
        }
        pst.day = 0 - nDays;
    }
    return pst;
}

long getDaysAmongDates(Date pst1, Date pst2)
{
    Date beg = pst1;
    Date end = pst2;
    long year, nDays = 0;
    if (!EqualDate(pst1, pst2))
    {
        if (!CompDate(pst1, pst2))
        {
            beg = pst2;
            end = pst1;
        }
        nDays = 365 - getDaysFromYearBeg(beg);
        nDays += CheckLongYear(beg.year);
        for (year = beg.year + 1; year < end.year; year++)
            nDays += 365 + CheckLongYear(year);
        nDays += CheckLongYear(year);
    }
    return nDays;
}

//��������� ��������� ���������� ���� �� ���������� ��������� ���
Date getRandDate(int min_year, int max_year)
{
    Date pst = { 0 };
    while (!CheckDate(pst))
    {
        pst.mon = 1 + rand() % 11;
        pst.day = 1 + rand() % (month_len[pst.mon - 1] - 1);
        pst.year = min_year + rand() % (max_year - min_year);
    }
    return pst;
}

//���������� �������� pst1 � pst2
void SwapDate(Date& pst1, Date& pst2)
{
    Date buf = pst1;
    pst1 = pst2;
    pst2 = buf;
}