#include <iostream>
#include <math.h>
using namespace std;

double intgral(double a, double b, int n, double eps)
{
    double res = 0, x = a, h = (b - a) / n;
    do
    {
        res += (sin(x) / x);
        x += h;
    } while (x < b && abs(res) > eps);
    res *= h;
    return res;
}
int main()
{
    double a, b, r, eps;
    int n;
    cout << "\nVvedit mezi integruvannia [a;b]:\n";
    do
    {
        cout << "\na = "; cin >> a;
        cout << "\nb = "; cin >> b;
    } while (a == 0 || b == 0);
    if (a > b)
    {
        double ñ = a;
        a = b;
        b = ñ;
    }
    do
    {
        cout << "\nVvedit tochnist eps > 0\neps = "; cin >> eps;
    } while (eps <= 0);
    do
    {
        cout << "\nVvedit chuslo vuzliv rozbuttia intervalu n>2\n";
        cout << "\nn = "; cin >> n;
    } while (n < 2);
    r = intgral(a, b, n - 1, eps);
    cout << "\nRezultat = " << r;
    return 0;
}