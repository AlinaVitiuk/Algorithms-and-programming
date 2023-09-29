//15.2.10.â
//15.2.10.b
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double eps, u, A, res(0);
    int i(0);
    do
    {
        cout << "\nVvedit tochnist eps>0\n eps = ";
        cin >> eps;
    } while (eps <= 0);
    cout << "Vvedit znachennia zminnoi  u = "; cin >> u;
    A = u;
    do
    {
        res += A;
        A *=-pow(u, 2)/((2+2*i)*(3+2*i++));
    } while (abs(A) > eps);
    cout << "\nRezultat: sin(" << u << ") = " << res << endl;
    return 0;
}