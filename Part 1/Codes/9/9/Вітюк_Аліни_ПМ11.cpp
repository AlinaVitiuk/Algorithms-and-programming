#include <iostream>
using namespace std;
double fun(double x) 
{
    return pow(x, 2) - 4;
} 
//������ �������;
int main()
{
    int c, d;
    double h, max, min, a;

    do
    {
        cout << "Vvedit mezhi [c,d]:";
        cout << "\nVvedit c = ";
        cin >> c;
        cout << "Vvedit d = ";
        cin >> d;
    } while (c > d or c == d);
    cout << "Vvedit krok h= "; cin >> h;
    max = fun(c);
    min = fun(c);
    for (; c <= d; c = c + h)
//����� max i min;
    {
        a = fun(c);
        if (a > max)
        {
            max = a;
        }
        else if (a < min)
        {
            min = a;
        }

    }
//���� ����������;
    cout << "Max znachennya = " << max << '\n';
    cout << "Min znachennya = " << min << '\n';
}