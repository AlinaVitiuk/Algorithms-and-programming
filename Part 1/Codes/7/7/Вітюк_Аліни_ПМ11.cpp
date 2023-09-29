#include <iostream>
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
void vyvid(int n, double a[])
{
    cout << "\nVvedenyi mnohochlen\n";
    for (int i = 0; i < n - 1; i++)
        cout << '(' << a[i] << ")*x^" << n - i - 1 << " + ";
    cout << '(' << a[n - 1] << ") = 0";
}
void form(int m, double a1[], double a2[])
{
    for (int i = 0; i < m; i++)
        a2[i] = a1[i] * (m - i);
}

double gorn(int n, double a[], double x)
{
    double res = a[0];
    for (int k = 1; k < n; res = res * x + a[k++]);
    return res;
}
int main()
{
    double a[size1 + 1] = { 0 }, b[size1] = { 0 }, x0, x1, P, eps;
    int n;
    do
    {
        cout << "\nVvedit ctepin mnohochlena n = "; cin >> n;
    } while (n < 1 || n > size1);
    do
    {
        cout << "\nVvedit tochnist eps > 0\neps = ";
        cin >> eps;
    } while (eps <= 0);
    cout << "\nVvedit pochatkove nablyzhennia x0 = "; cin >> x0;
    cout << "\nVvedit koeficientu mnohochlena a_0*x^n + a_1*x^(n-1) +... + a_(n - 1) * x + a_n:\n";
    vvid(n + 1, a);
    form(n, a, b);
    vyvid(n + 1, a);
    x1 = x0;
    do
    {
        x0 = x1;
        P = gorn(n, b, x0);
        if (P == 0)
        {
            x0 += eps;
            P = gorn(n, b, x0);
        }
        x1 = x0 - gorn(n + 1, a, x0) / P;
    } while (abs(x1 - x0) > eps);
    cout << "\n\n*** Korin = " << x1 << " ***\n";
    return 0;
}