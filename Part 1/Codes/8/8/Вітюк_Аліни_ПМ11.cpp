#include<iostream>
#include<math.h>
using namespace std;
double fun(double x) {
    return pow(x, 2) + 2 * x - 2;
}
//Задання функції 
int main() {
    double a, b, h, f1, f2, c, eps, yg, yz, yc, f, z, g;
    int flag1 = 0;
    do
    {
        cout << "Vvedit krok h = ";
        cin >> h;
        cout << "Vvedit tochnist eps = ";
        cin >> eps;
    } while (h < 0 or eps < 0);
 //Знаходження сегментів, де функці змінює знак і уточнення коленів із заданою точністю методом половинного ділення;
    do
    {
        cout << "Vvedit mezhi [a,b]:";
        cout << "\nVvedit a = ";
        cin >> a;
        cout << "Vvedit b = ";
        cin >> b;
    } while (a > b or a == b);
    do
    {
        f1 = fun(a);
        f2 = fun(a + h);
        if (f1 * f2 < 0)
        {
            int flag2 = 0;
            flag1 = 1;
            cout << "\nZnak zminyuyetsya na intervali [" << a << "," << a + h << "]" << endl;
            g = a;
            z = a + h;
            yg = fun(g);
            yz = fun(z);
            if (yg == 0)
            {
                flag2 = 1;
                cout << "\nKorin x = " << g << " f(x) = " << yg;
            }
            if (yz == 0)
            {
                flag2 = 1;
                cout << "\nKorin x = " << z << " f(x) = " << yz;
            }
            while (abs(g - z) >= eps)
            {
                c = (g + z) / 2;
                yc = fun(c);
                if (yc == 0)
                {
                    cout << "\nKorin x = " << c << "\tf(x) = " << yc;
                    flag2 = 1;
                }
                else if (yg * yc < 0)
                {
                    z = c;
                    yz = yc;
                }
                else if (yz * yc < 0)
                {
                    g = c;
                    yg = yc;
                }
            }
            if (flag2 == 0)
            {
                c = (g + z) / 2;
                cout << "\nKorin x = " << c << " f(x) = " << fun(c) << endl;
            }
        }
        a = a + h;
    } while (a < b);
//Вивід інформаціїпро те, що функція знакостала;
    if (flag1 == 0)
    {
        cout << "Na vsomu intervali znak f(x) ne zminyuyetsya";
    }
    return 0;
}