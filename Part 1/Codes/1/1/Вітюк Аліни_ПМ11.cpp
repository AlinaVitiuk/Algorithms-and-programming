#include<iostream>
#include<math.h>
using namespace std;
double fun(double x) 
{
    return pow(x, 2) + 2 * x - 2;
}
int main() {
    double a, b, h, f1, f2;
    int flag = 0;
    do
//Введення кроку, який повинен бути більше 0;
    {
        cout << "Vvedit krok h = ";
        cin >> h;
    } while (h < 0);
    do
//Введення меж інервалу;
    {
        cout << "Vvedit mezhi [a,b] =";
        cout << "\nVvedit a =";
        cin >> a;
        cout << "Vvedit b = ";
        cin >> b;
    } while (a > b or a == b);
//Знаходження сегментів, де функція змінює знак;
    do
    {
        f1 = fun(a);
        f2 = fun(a + h);
        if (f1 * f2 < 0)
        {
            flag = 1;
//Виведення знайдених сегментів
            cout << "Znak zminyuyetsya na intervali [" << a << "," << a + h << "]" << endl;
        }
        a = a + h;
    } while (a < b);
//Вивід інформації про відсутність сегментів, де фенкція змінює знак;
    if (flag == 0)
    {
        cout << "Na vsomu intervali znak f(x) ne zminyuyetsya";
    }
    return 0;
}