//�������� ���������� ��������� �����, ����� ������� ����� ������������ ����'������. 
//�������� ������� ��������� �� ������ ������ ������� �� ������� ������� �� ���������� ���� ���������� ������, 
//� ����� ������� ��������� ��������� �������.
//����������� ��������� ���������� �� ��������� ������ ������� ���� �� �������.
//���������� ���������� �a �����.

#include <iostream>     // �������� � ��������� ���������� ����
#include <Windows.h>    // ���������� ����������� �����
#include<time.h>        //���������� ����, �� ������ ���� � ������� ��� ������ � ����� � �����.
using namespace std;

int menu();//����
int** Create_mtrx(int**, int&, int&);        //��������� �������
void Print_mtrx(int**, int, int);            //���� �������
int** Insert_column(int**, int&, int&);      //��������� �� ������ ������ �����
int** Delete_column(int**, int&, int&);      //��������� ��������� �����
bool Is_empty_array(int);                    //�������� ��������� �������
void Delete_mtrx(int**, int&);               //��������� �������

int main()
{
	SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����
	int n = 0, m = 0, choice, ** a = NULL;
	
	while ((choice = menu()) != 5)
	{
		switch (choice)  //���� ������ � ����� ����
		{
		case 1: a = Create_mtrx(a, n, m); break;
		case 2: if (!Is_empty_array(n)) Print_mtrx(a, n, m); break;
		case 3: if (!Is_empty_array(n)) a = Insert_column(a, n, m); break;
		case 4: if (!Is_empty_array(n)) a = Delete_column(a, n, m); break;
		case 5: break;
		default: cout << "���i���� ���i�!\n"; break;
		}
		cout << "\n\n";
	}
	if (n) Delete_mtrx(a, n);
	cout << "\n�i���� ��������.\n";
}

int menu()
{
	float choice;
	cout << "\n\t\t~ ���� ~\n";
	cout << "���i� �������:\n\t\t";
	cout << "1 - �������� �������\n\t\t";
	cout << "2 - ���� ������i\n\t\t";
	cout << "3 - ��������� �������\n\t\t";
	cout << "4 - ��������� �������\n\t\t";
	cout << "5 - ���i�\n";
	cout << "����i�� ��� ���i�: ";
	cin >> choice;
	return (int)choice;
}
int** Create_mtrx(int** array, int& n, int& m)//��������� �������
{
	cout << "\n\n~��������� ������i~\n";
	do
	{
		cout << "\n\t����i�� ������� ����i�: ";
		cin >> n;
	} while (n <= 0);
	{
		cout << "\t����i�� ������� ������i�: ";
		cin >> m;
	} while (m <= 0);
	array = new int* [m];
	int c = 10, d = 100;
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
		for (int j = 0; j < n; j++)
		array [i] [j] = rand() % (d - c);
	}
	cout << "\n������� ��������!\n";
	return array;
}

void Print_mtrx(int** array, int n, int m)//���� �������
{
	
	int** array_t; // ������������� ������� 
	array_t = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array_t[i] = new int[m];
	}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				*(*(array_t + j) + i) = array[i][j];
			}
		}
		cout << "�������\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << array_t [i][j];
		}
		cout << "\n";
	}

}

int** Insert_column(int** array, int& n, int& m)//��������� �� ������ ������ �������
{
	int k, j = 0;
	do
	{
		cout << "\n� ������i " << m << " ��������.\n";
		cout << "\t����i�� ����� �������� ��� ������� = ";
		cin >> k;
	} while (k <= 0 || k > m + 1);
	k--;
	int** new_array = new int* [++m];
	for (int i = 0; i < m; i++)
	{
		if (i == k)
		{
			new_array[i] = new int[n];
			int c = 10, d = 100;
			for (int j = 0; j < n; j++)
				*(*(new_array + i) + j) = rand() % (d - c);
			j = 1;
		}
		else *(new_array + i) = *(array + i - j);
	}
	cout << "\n�������� ������!\n";
	delete[]array;
	return new_array;
}

int** Delete_column(int** array, int &n, int& m)//��������� ��������� �������
{
	int k, j = 0;
	do
	{
		cout << "\n� ������i " << m << " ��������\n";
		cout << "\t����i�� ����� ������� ��� ��������� = ";
		cin >> k;
	} while (k <= 0 || k > m);
	k--;
	int** new_array = new int* [--m];
	for (int i = 0; i < m; i++)
	{
		if (i == k) j = 1;
		*(new_array + i) = *(array + i + j);
	}
	cout << "\n�������� ��������!\n";
	delete[]array[k];
	delete[]array;
	return new_array;
}

bool Is_empty_array(int n)//�������� ��������� �������
{
	if (!n) cout << "\n������� �������!\n";
	return (n) ? false : true;
}

void Delete_mtrx(int** array, int& n)//��������� �������
{
	for (int i = 0; i < n; i++)
		delete[]array[i];
	delete[]array;
	n = 0;
}