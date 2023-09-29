/* Приклад 3 */
/* Функції як поля структур */
#include<iostream>
#include<cstdlib>
using namespace std;

struct Fraction
{
	int numerator, denominator; /* чисельник і значенник */
	void EnterFraction(const char*); /* введення дробу */
	void PrintFraction(const char*); /* друк дробу */
	void CreateFraction(int, int = 1); /* встановлення нового дробу */
	void SimplifyFraction(); /* спрощення дробу */
	Fraction Sum(Fraction &); /* сума дробів */
};

int EnterNumber(const char*); /* введення числа*/
int CommonDivisor(int, int); /* найбільший спільний дільник */

void main()
{
	setlocale(LC_ALL, "ukr");
	struct Fraction a, d; /* оголошення двох змінних типу Fraction*/
	a.EnterFraction("a"); /* виклик поля-функції для введення дробу */
	a.SimplifyFraction(); /* виклик поля-функції для спрощення дробу */
	a.PrintFraction("a");
	d = a; /* переприсвоєння двох дробів */
	d.CreateFraction(3, 0); d.PrintFraction("d"); /* встановлення нових значень чисельника і знаменника */
	struct Fraction b = { 2,3 }; b.PrintFraction("b"); /* оголошення та ініціалізаця нової змінної типу Fraction */
	a.PrintFraction("a");
	struct Fraction c = a.Sum(b); /* додавання дробів a i b */
	c.PrintFraction("(c=a+b)");
	cout << "\nEND.\n";
}
int CommonDivisor(int a, int b) /* найбільший спільний дільник */
{
	if (!b) /* якщо b = 0 */
		return a; /* повернення a*/
	return CommonDivisor(b, a%b); /* рекурсивний виклик функції CommonDivisor, де другий параметр - це остача від ділення a на b */
}
int  EnterNumber(const char*ms) /* введення числа*/
{
	cout << "Введiть " << ms << " = ";
	char s[10];
	cin.getline(s, 10); /* читання введеної стрічки */
	return atoi(s); /* стрічка s конвертується в int */
}

void Fraction::EnterFraction(const char *ms) /* введення дробу (розширення контексту ::) */
{
	cout << "Введiть дрiб " << ms << " \n";
	numerator = (int)EnterNumber("чисельник"); /* введення чисельника */
	do
	{
		denominator = (int)EnterNumber("знаменник"); /* введення знаменника */
	} while (!denominator); /* поки знаменник = 0 */
}
void Fraction::PrintFraction(const char *ms) /* друк дробу (розширення контексту ::) */
{
	cout << "Дрiб " << ms << " = " << numerator << '/' << denominator << endl;
}

void Fraction::CreateFraction(int c, int b) /* встановлення нового дробу (розширення контексту ::) */
{
	numerator = c; /* встановлення нового значення чисельника*/
	denominator = (b) ? b : 1; /* встановлення нового значення знаменника, відмінного від 0 */
}

void Fraction::SimplifyFraction() /* спрощення дробу (розширення контексту ::) */
{
	int a = CommonDivisor(abs(numerator), abs(denominator)); /* найбільший спільний дільник чисельника і знаменника */
	numerator /= a; denominator /= a; /* скорочення чисельника і знаменника на НСД */
	int b = abs(denominator);  a = abs(numerator);
	numerator = (numerator*denominator > 0) ? a : -a; /* якщо чисельник і знаменник однакового знаку, то знак дробу +, інакше -*/
	denominator = b;
}
Fraction Fraction::Sum(Fraction &b) /* сума дробів (розширення контексту ::) */
{
	Fraction a; /* оголошення нової змінної типу Fraction */
	a.denominator = denominator * b.denominator; /* тут denominator - це заменник дробу з головної програми, в якому викликали поле-функцію Sum*/
	a.numerator = numerator * b.denominator + denominator * b.numerator; /* тут numerator - це чисельник дробу з головної програми, в якому викликали поле-функцію Sum*/
	a.SimplifyFraction();
	return a; /* результат виконання функції - змінна типу Fraction */
}