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

//Делаю индексацию с 0-цы для простоты
//0 - январь 11 - декабрь
int month_len[] = {31,28,31,30,31,30,31,31,30,31,30,31};

char* getTextDate(Date pst);
//Ввод даты
bool EnterDate(Date& pst);
//Проверка корректности даты
 
//проверка года на вискосность
bool CheckLongYear(int year);
//возвращаемое значение - строка с текстовым форматом даты

bool CheckDate(Date pst);
//количество дней, прошедших с начала года
long getDaysFromYearBeg(Date pst);
//Проверяет равенство дат pst1 и pst2
bool EqualDate(Date pst1, Date pst2);
//Проверяет меньше ли дата pst1 чем pst1
bool CompDate(Date pst1, Date pst2);
//функция будет производить запрос ввода
//пока не будет введенакорректная дата
Date EnterDate();
//Функция возвратит дату отличную от данной на число дней nDays
Date getDateWithDiference(Date pst, long nDays);
//Возвращает число дней между 2-мя датами
long getDaysAmongDates(Date pst1, Date pst2);
//Рандомная генерация корректной даты из указанного диапазона лет
Date getRandDate(int min_year, int max_year);
//Обменивает значения pst1 и pst2
void SwapDate(Date& pst1, Date& pst2);

//Функции обработчики пунктов меню
void p1();
void p2();
void p3();
//Данная функция отвечает за динамическое выделение памяти 
//по адресу ptr (сразу скажу что для студии можно было обойтись и 
//без фильтации bad_alloc, но делаю по всем канонам)
template <class T>
T* alloc_mem(T* ptr, unsigned long count);

int main()
{
	//зміна кодування для використання кирилиці при вводі та виводі 
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
    while (true)
    {
        system("cls");
        cout << "\t***MENU***\n";
        cout << "1 - три наиболее близких даты, с невисокосным годом;\n";
        cout << "2 - дата, наиболее близкая к заданной дате D\n";
        cout << "    и генерация всех дат в рамках того же года,\n";
        cout << "    отстоящие от найденной на 15k дней\n";
        cout << "3 - вывод даты в формате ДД месяц ГГГГ\n";
        //кто рассово не приемлит getch уж введите замену сами - это пара мин дела
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

    cout << "Введите N : ";
    if (!(cin >> N))
        cout << "Ошибка ввода\n";
    else
        if (!(array = alloc_mem(array, N + 1)))
            cout << "Ошибка выделения памяти под массив дат\n";
        else
        {
            array[0] = EnterDate();
            cout << "Массив сгененрированных дат\n";
            for (i = 1; i <= N; i++)
            {
                //Генерируем случайным образом массив дат
                array[i] = getRandDate(-100, 2100);
                if (!strcpy(sDate, getTextDate(array[i])))
                    cout << "Ошибка вывода строкового описания даты\n";
                else
                    cout << sDate << endl;
            }
            //Чтобы вывести 3 близких даты
            //отсортируем наш массив по убыванию
            //тогда первые даты будут наиболее близкими
            for (i = 1; i <= N; i++)
                for (j = i + 1; j <= N; j++)
                {
                    if (CompDate(array[i], array[j]))
                        SwapDate(array[i], array[j]);
                }
            cout << "Наиболее близкие даты с невисокосным годом\n";
            for (i = 1; i <= N; i++)
            {
                if (!strcpy(sDate, getTextDate(array[i])))
                    cout << "Ошибка вывода строкового описания даты\n";
                else
                    cout << sDate << endl;
            }
            delete[] array;//Чистим память
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
            cout << "Ошибка вывода строкового описания даты\n";
        else
            cout << sDate << endl;
    }
}

void p3()
{
    char sDate[12] = { 0 };
    Date pst = EnterDate();
    if (!strcpy(sDate, getTextDate(pst)))
        cout << "Ошибка вывода строкового описания даты\n";
    else
        cout << sDate << endl;
}

//проверка года на вискосность
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

//Ввод даты
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

//Проверка корректности даты
bool CheckDate(Date pst)
{
    //т.е високосный год и февраль
    int addDays = (CheckLongYear(pst.year) && pst.mon == 1) ? 1 : 0;
    bool bCorrect = true;
    if (pst.mon < 1 || 12 < pst.mon)
        bCorrect = false;
    else
        if (!pst.day || (month_len[pst.mon - 1] + addDays < pst.day))
            bCorrect = false;
    return bCorrect;
}

//функция будет производить запрос ввода
//пока не будет введенакорректная дата
Date EnterDate()
{
    Date pst = { 0 };
    //Будем крутиться в цикля пока всё таки не введём норм дату
    while (true)
    {
        //Наша исходная дата будет с 0 индексом
        cout << "Введите исходную дату\n";
        if (!EnterDate(pst))
            cout << "Ошибка ввода\n";
        else
            if (!CheckDate(pst))
                cout << "Введена некорректная дата\n";
            else
                break;
    }
    return pst;
}

//количество дней, прошедших с начала года
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
//Проверяет равенство дат pst1 и pst2
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

//Проверяет меньше ли дата pst1 чем pst1
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

//Функция возвратит дату отличную от данной на число дней nDays
Date getDateWithDiference(Date pst, long nDays)
{
    if (nDays < pst.day)
        pst.day -= nDays;
    else//Будем крутиться по месяцам и годам пока не исчерпаем дни
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

//Рандомная генерация корректной даты из указанного диапазона лет
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

//Обменивает значения pst1 и pst2
void SwapDate(Date& pst1, Date& pst2)
{
    Date buf = pst1;
    pst1 = pst2;
    pst2 = buf;
}