#include<iostream>
using namespace std;
int main()
{
    int a[] = { 3,-8,5,0,-1,-9,8,0 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Zadanuy masyv:\n";
    for (int i = 0; i < n; cout << "\t" << a[i++]);
    for (int i = 0, j = 0; i < n; i++, j++)
        if (a[j] < 0)
        {
            int b = a[j];
            for (int k = j; k < n - 1; k++)
            {
                a[k] = a[k + 1];
            }
            a[n - 1] = b; j--;
        }
    for (int i = 0, j = 0; i < n; i++, j++)
        if (a[j] == 0)
        {
            int b = a[j];
            for (int k = j; k < n - 1; k++)
            {
                a[k] = a[k + 1];
            }
            a[n - 1] = b; j--;
        }
    cout << "\nVporiadkovanyi masyv:\n";
    for (int i = 0; i < n; cout << "\t" << a[i++]);
    return 0;
}