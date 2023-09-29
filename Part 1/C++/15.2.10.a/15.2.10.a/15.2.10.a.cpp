//15.2.10.a
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double eps, u, A, res(0);
	int i(1);
    do
    {
        cout << "\nVvedit tochnist eps >0\n eps = ";
        cin >> eps;
    } while (eps <= 0);
    cout << "Vvedit znachennia zminnoi  u = "; cin >> u;
    A = 1;
    do
    {
        res += A;
        A *= u / (i++);
    } while (abs(A) > eps);
    cout << "\nRezultat: e^(" << u << ") = " << res << endl;
    return 0;
}