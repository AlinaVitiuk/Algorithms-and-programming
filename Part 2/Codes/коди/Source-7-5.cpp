/* Приклад 5 */
/* Шаблонні структури */
#include <iostream>
using namespace std;
template <class A, class B> /* оглошення шаблонної структури T_Struct */
struct T_Struct /* взірець самої структури */
{
	A a; B b; /* опис полів структури */
};
typedef T_Struct <int, int> t_type; /* t_type - нове ім'я для структури T_Struct з двома цілими полями */

template <class A, class B> /* оголошення шаблонної структури T_Struct_2 */
struct T_Struct_2 /* взірець самої структури */
{
	A a; B b; /* опис полів структури */
};
int main()
{
	t_type obj = { 1,2 }; /* оголошення змінної типу структури з двома цілими полями */
	T_Struct_2<double, double> dane = { 3.14,2.72 }; /* оголошення змінної типу структури з двома дійсними полями */
	cout << "\n\tobj = " << obj.a << "\t" << obj.b << endl; /* виведення полів структури на екран */
	cout << "\n\tdane = " << dane.a << "\t" << dane.b << endl;
	return 0;
}