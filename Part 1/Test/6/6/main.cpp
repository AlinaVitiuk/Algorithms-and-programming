#include <iostream>
#include <math.h>
using namespace std;
const int size1 = 10;
void vvid(int m, double a[])
{
    for (int i = 0; i < m; i++)
    {
        cout << "a_" << i << " = ";
        cin >> a[i];
    }
}
void form(int m, double a1[], double a2[])
{
    for (int i = 0; i < m; i++)
        a2[i] = a1[i] / (m + 1 - i);
}
double gorn(int n, double a[], double x)
{
    double res = a[0];
    for (int k = 0; k < n; res = res * x + (1 / (n + k++)));
    res = res * x;
    return res;
}
int main()
{
    double a[size1 + 1] = { 0 }, b[size1] = { 0 }, x2 = 5.76, x1 = 2.34, P1, P2, C;
    int n;
    do
    {
        cout << "\nVvedit ctepin mnohochlena n = "; cin >> n;
    } while (n < 1 || n > size1);
    cout << "\nVvedit koeficientu mnohochlena a_0*x^n + a_1*x^(n-1) +... + a_(n - 1) * x + a_n:\n";
    vvid(n + 1, a);
    form(n, a, b);
    P1 = gorn(n, a, x1);
    P2 = gorn(n, b, x2);
    C = P2 - P1;
    cout << "Znachenia integrala vid 2.34 do 5.76 = " << C;
    return 0;
}