/* ������� 4 */
/* ������������ ��������� ������� */
#include <iostream> 
template <class T> /* �������� �������� ������� */
// ��� template <typename T>
void Swap(T &�, T &�);
int main()
{
	using namespace std;
	int i = 10;
	int j = 20; /* ���������� ���� ������ ������ ���� */
	cout << "i, j = " << i << ", " << j << "\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j); /* ������ void Swap(int &, int &) */
	cout << "Now i, j = " << i << ", " << j << ".\n\n";
	double x = 24.5;
	double y = 81.7; 	/* ���������� ���� ������ ������� ���� */
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x, y); // ������ void Swap(double &, double &) 
	cout << "Now x, y = " << x << ", " << y << ".\n";
	return 0;
}

template <class T> /* ��������� �������� �������*/
// ��� template <typename T>
void Swap(T &a, T &b)
{
	T temp; /* temp - ����� ���� �  */
	temp = a;
	a = b;
	b = temp;
}