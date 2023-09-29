#include <iostream>
#include <math.h>
using namespace std;
double f(double z) //Задання функції
{
    return pow(z, 3) - 8;
}
int main()
{
    double c, d, e, eps, yc, yd, ye;
    do
    {
        cout << "\nVvedit tochnist eps >0\n eps = "; cin >> eps;
    } while (eps <= 0);
    cout << "\nVvedit mezi intervalu [c;b]\n c = "; cin >> c;
    cout << "\n d = "; cin >> d;
//Уточнення корення методом поовинного ділення
    if (c > d)
    {
        double r = c; c = d; d = r;
    }
    yc = f(c); yd = f(d);
    if (yc * yd < 0)
    {
        while (abs(c - d) >= eps)
        {
            e = (c + d) / 2; ye = f(e);
            if (ye == 0)
            {
                cout << "\nKorin x = " << e << "\tF(x) = " << ye;
                return 0;
            }
            else
                if (yc * ye < 0)
                {
                    d = (c + d) / 2; yd = ye;
                }
                else
                    if (yd * ye < 0)
                    {
                        c = (c + d) / 2; yc = ye;
                    }
        }
    }
//Вивід результату
    else
    {
        cout << "\nKoreniv nemaie!";
        return 0;
    }
    e = (c + d) / 2;
    cout << "\n Korin x = " << e << " F(x) = " << ye;
    return 0;
}