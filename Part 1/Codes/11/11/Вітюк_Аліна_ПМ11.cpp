#include <iostream>
#include <math.h>
using namespace std;
const int k = 10;
//Задання коефіцієнтів многочлена 
void vvid(int m, double a[])
{
    for (int i = 0; i <= m; i++)
    {
        cout << "a_" << i << " = ";
        cin >> a[i];
    }
}
void form(int m, double a[])
{
    for (int i = 0; i <= m; i++) {
        a[i] = a[i] / (m + 1 - i);
    }
}
//Обчислення інтегралу у точках 2.34 та 5.76
double gorn(int n, double a[], double x)
{
    double s = a[0];
    for (int i = 1; i <= n; s = s * x + a[i++]);
    s = s * x;
    return s;
}
int main()
{
    double a[k] = { 0 }, x1 = 2.34, x2 = 5.76, P1, P2, I;
    int n;
//Формуванння многочлена 
    do
    {
        cout << "Vvedit stepin mnohochlena n = ";
        cin >> n;
    } while (n < 1 or n > k - 1);
    cout << "\nVvedit koefitsiyenty mnohochlena:\n";
    vvid(n, a);
    form(n, a);
 //Обчислення інтегралу 
    P1 = gorn(n, a, x1);
    P2 = gorn(n, a, x2);
    I = P2 - P1;
    cout << "Znachennya intehrala vid 2.34 do 5.76 = " << I;
    return 0;
}