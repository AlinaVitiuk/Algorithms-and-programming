/* Приклад 4 */
/* Використання шаблонних функцій */
#include <iostream> 
template <class T> /* Прототип шаблонної функції */
// або template <typename T>
void Swap(T &а, T &Ь);
int main()
{
	using namespace std;
	int i = 10;
	int j = 20; /* оголошення двох змінних цілого типу */
	cout << "i, j = " << i << ", " << j << "\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j); /* генерує void Swap(int &, int &) */
	cout << "Now i, j = " << i << ", " << j << ".\n\n";
	double x = 24.5;
	double y = 81.7; 	/* оголошення двох змінних дійсного типу */
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x, y); // генерує void Swap(double &, double &) 
	cout << "Now x, y = " << x << ", " << y << ".\n";
	return 0;
}

template <class T> /* Означення шаблонної функції*/
// або template <typename T>
void Swap(T &a, T &b)
{
	T temp; /* temp - змінна типу Т  */
	temp = a;
	a = b;
	b = temp;
}