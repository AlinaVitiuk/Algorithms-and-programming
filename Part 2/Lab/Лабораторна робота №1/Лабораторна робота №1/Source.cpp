#include<iostream>      // бібліотека і відповідний заголовний файл
#include<math.h>        // математична бібліотека
#include <iomanip>
using namespace std;    // директива для всіх ідентифікаторів в просторі імен

double f(double x)
{
    return ((x - tan(x)) * sqrt(x));
}
// Задання функції

int main()
{
    double y, a, b; 
    int n;
//y - функція;
//a - початок інтервалу табулювання; 
//b - кінець інтервалу табулювання;
//n - кількість вузлів табулювання;

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
// ввід даних;

    double h = (b - a) / (n - 1); 
    double min = f(a), max = f(a), x_min = a, x_max = a;
// h - крок табулювання;
// min - мінімальне значення функції;
// max - максимальне значення функції;
// x_min - значення аргументу, при якому функція набуває мінімального значення;
// x_max - значення аргументу, при якому функція набуває максимального значення.
    
    cout << " " << endl;
    cout << "f(x)=(x-tan(x))*sqrt(x)" << endl;
    cout << "----------------------------" << endl;
    cout << setw(6) << left << "x" << "\t|" << "f(x)" << endl;
    cout << "----------------------------" << endl;
  
    for (; a <= b; a = a + h)
    {
        y = f(a);  
// знаходження значень функції f(x)=(x-tg(x))*sqrt(x), на інтервалі [a, b] з кроком h;
        cout << setprecision(4) << fixed << setw(6) << left << a << "\t|" << fixed << setw(10) << setfill (' ') << y << endl;
        cout << "----------------------------" << endl;
// вивід значень f(x) та x таблиці;
        
        if (y > max)
        {
            max = y; x_max = a;
        }
        else if (y < min)
        {
            min = y; x_min = a;
        }
// знаходження максимального/мінімального значення функції та відповідного аргументу методом порівняння елеметів;
    } 
    
    cout << "min=f(" << x_min << ")=" << min << endl;
    cout << "max=f(" << x_max << ")=" << max << endl;
 // вивід результату;
    return 0;
}