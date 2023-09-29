#include"decl_file.h"

/* введення числа */
int EnterNumber() 
{
	char rez[15];
	gets_s(rez);
	return atoi(rez);
}

/* введення дробів */
void EnterArrayFraction(Fraction* a, int n) 
{
	cout << "\nУвага! Вводьте нескоротні дроби.";
	cout << "\nФормат дробів a / b (a - чисельник, b - знаменник)\n";
	for (int i = 0; i < n; i++)
		a[i].EnterFraction();
	cout << "\nДроби введено\n";
}

/* введення дробів */
void PrintArrayFraction(Fraction* a, int n) 
{
	cout << "\nВведені дроби:";
	for (int i = 0; i < n; i++)
	{
		cout << "\nДріб_" << i;
		a[i].PrintFraction();
	}
	cout << "\n";
}

/*дроби з непарними чисельниками */
void SearchArrayFraction(Fraction* a, int n) 
{
	cout << "\nДроби з непарними чисельниками: ";
	bool flag = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i].numerator % 2 != 0) 
		{
			cout << "\nДріб_" << i;
			a[i].PrintFraction();
			flag = 1;
		}
		if (flag == 0) 
		{
			cout << "\nДробів з непарними чисельниками не знайдено";
		}
	}
	cout << "\n";
}

/* введення конкретного дробу */
void Fraction::EnterFraction() 
{ 
	do
	{
		cout << "\nВводьте дріб: \n";
		cout << "a: ";
		numerator = (int)EnterNumber();
		cout << "b: ";
		denominator = (int)EnterNumber();
		if (numerator != 1 && (denominator % numerator != 0 || numerator % denominator != 0))
		{
			cout <<"Вводьте нескоротні дроби\n" ;
		}
	} while (numerator !=1 && denominator % numerator == 0 || numerator % denominator == 0);

}

/* вивід дробів */
void Fraction::PrintFraction() {
	cout << "     " << numerator << "/" << denominator;
}

