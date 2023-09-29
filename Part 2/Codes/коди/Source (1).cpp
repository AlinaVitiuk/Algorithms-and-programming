/*�������� ���������� ��������� ����� �������, �� ����� �����
���� ���� ���� ���������, ������� �� ������� ��������� ������
(�������).����������� ��� ����� ����, ���� �� ���� ������� �������
������.������� �� ����� �������� �����, � ���, �������������� ���������,
������������ ���� ���, ��� ����� �������� ������ ���� �� �������� ��
����������.*/

#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning (disable :4996)
using namespace std;

enum 
{
    choice_Print=1, choice_Sort, choice_Quit
};

int input_number(const char*);              //�������� �����
int menu();                                 //����
char** Add_line(char**, int&, int&);        //�������� ������ 
void Sort_lines(char**&, int);              //������������� ������ (����� ��������� ����� ������ �� ���������)
void Print_text(char**, int, const char*);  //���� ������ �� �����
void Delete_all_lines(char**&, int&);       //�������� ������ ������

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //���� ��������� ��� ������������ �������� ��� ���� �� �����

    char** text = 0; int n = 0, m=0, choice;
    cout << "\n\t������ �����\n";
    cout << "��� ���������� �������� ���� ENTER\n";
    do {
        text = Add_line(text, n, m);
    } while (m != 0);
    
	while ((choice = menu()) != choice_Quit)
    {
        switch (choice)
        {
        case choice_Print: Print_text(text, n, "�����"); break;
        case choice_Sort: Sort_lines(text, n); break;
        case choice_Quit: break;
        default:cout << "\n���i���� ���i�\n"; break;
        };
    }
    cout << "\n�i���� ��������\n";
    return 0;
}

int menu() //����
{
    int choice;
    cout << "\n\t�������� 䳿 � �������:\n"
        << choice_Print << " - ���� ������\n"
        << choice_Sort << " - ������������� ������ (����� ��������� ����� ������ �� ���������)\n"        
        << choice_Quit << " - ��ղ�\n\n";
    choice = input_number("��� ���i�");
    return choice;
}

int input_number(const char* ms) //�������� �����
{
    char rez[10];
    cout << "������ " << ms << " = ";
    gets_s(rez);
    return atoi(rez);
}

char** Add_line(char** a, int& n, int& m) //�������� ������
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

void Delete_all_lines(char**& a, int& n) //�������� ������ ������
{
    for (int i = 0; i < n; i++)
        delete[]a[i];
    delete[]a;
    n = 0;
}

void Print_text(char** a, int n, const char* ms) //���� ������ �� �����
{

        cout << "\n*** " << ms << " ***\n";
        for (int i = 0; i < n; i++)
            cout << *(a + i) << endl;
}

void Sort_lines(char**& a, int n) //������������� ������ (����� ��������� ����� ������ �� ���������) 
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
    cout << "����� ������������!\n";
}

