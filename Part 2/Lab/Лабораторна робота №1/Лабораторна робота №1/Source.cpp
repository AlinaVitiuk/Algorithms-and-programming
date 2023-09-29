#include<iostream>      // �������� � ��������� ���������� ����
#include<math.h>        // ����������� ��������
#include <iomanip>
using namespace std;    // ��������� ��� ��� �������������� � ������� ����

double f(double x)
{
    return ((x - tan(x)) * sqrt(x));
}
// ������� �������

int main()
{
    double y, a, b; 
    int n;
//y - �������;
//a - ������� ��������� �����������; 
//b - ����� ��������� �����������;
//n - ������� ����� �����������;

    do
    {
        cout << "\nVvedit a i b (bilshi nulya)";
        cout << "\na = "; cin >> a; 
        cout << "\nb = "; cin >> b; 
    } while (a < 0 || b < 0 || a > b || a == b );
    do
    {
        cout << "\nVvedit n (n - tsile chyslo, bilshe odynytsi)";
        cout << "\nVvedit n = "; cin >> n; 
    } while (n <= 1);
// ��� �����;

    double h = (b - a) / (n - 1); 
    double min = f(a), max = f(a), x_min = a, x_max = a;
// h - ���� �����������;
// min - �������� �������� �������;
// max - ����������� �������� �������;
// x_min - �������� ���������, ��� ����� ������� ������ ���������� ��������;
// x_max - �������� ���������, ��� ����� ������� ������ ������������� ��������.
    
    cout << " " << endl;
    cout << "f(x)=(x-tan(x))*sqrt(x)" << endl;
    cout << "----------------------------" << endl;
    cout << setw(6) << left << "x" << "\t|" << "f(x)" << endl;
    cout << "----------------------------" << endl;
  
    for (; a <= b; a = a + h)
    {
        y = f(a);  
// ����������� ������� ������� f(x)=(x-tg(x))*sqrt(x), �� �������� [a, b] � ������ h;
        cout << setprecision(4) << fixed << setw(6) << left << a << "\t|" << fixed << setw(10) << setfill (' ') << y << endl;
        cout << "----------------------------" << endl;
// ���� ������� f(x) �� x �������;
        
        if (y > max)
        {
            max = y; x_max = a;
        }
        else if (y < min)
        {
            min = y; x_min = a;
        }
// ����������� �������������/���������� �������� ������� �� ���������� ��������� ������� ��������� �������;
    } 
    
    cout << "min=f(" << x_min << ")=" << min << endl;
    cout << "max=f(" << x_max << ")=" << max << endl;
 // ���� ����������;
    return 0;
}