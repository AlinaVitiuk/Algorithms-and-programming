//15.2.24 â)

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double eps, u, A, res(0), a, b, resa(0), resb(0);
    int i(1);
    do
    {
        cout << "\nVvedit mezhi integruvannia [a,b]";
        cout << "\n a= "; cin >> a;
        cout << "\n b= "; cin >> b;
    } while (a > b);
    do
    {
        cout << "Vvedit eps>0 \n eps = ";
        cin >> eps;
    } while (eps <= 0);
    u = b;
    A = u;
    int fact = 1;
    fact *= i;
    i++;
    do
    {
        resb += A;
        A = A *(pow(u, (i + 0.5)) / ((i++ + 0.5) * (fact)));
    } while (abs(A) > eps);
    u = a;
    A = u;
    do
    {
        resa += A;
        A = A * (pow(u, (i + 0.5)) / ((i++ + 0.5) * (fact)));
    } while (abs(A) > eps);
    res = resb - resa;
    cout << "Rezultat: e^(-x^2)= " << res << endl;
    return 0;
}