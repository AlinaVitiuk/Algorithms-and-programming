#include <iostream>
using namespace std;

const int N = (int)1e5 + 1;

string number;
int a[N];

int main()
{
    cout << "Vvedit chuslo  N = "; cin >> number;
    int idx = 0;
    for (int i = 0; i < number.length(); i++) {
        a[idx] = number[i] - '0';
        idx++;
    } //Формування масиву
    for (int i = 0; i < idx; i++) 
    {
        cout << "Element_" << i << "=" << a[i] << endl; //Вивід масиву
    }
    return 0;
}