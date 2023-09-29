#include <iostream>
using namespace std;
typedef int dani;
const int size1 = 5, size2 = 9;
int main()
{
    dani f[size1] = { 2, 9, -20, 77, 41 };
    dani g[size2] = { 7, 8, 9, 100, 77, 2, 142, 900, -18 };
    dani ff[size1] = { 0 };
    int n = size1, m = size2;
    cout << "\nMasyv #1:\n";
    for (int i = 0; i < n; cout << f[i++] << '\t');
    cout << "\nMasyv #2:\n";
    for (int i = 0; i < m; cout << g[i++] << '\t');

    cout << "\n\nPeretyn masyviv:\n";
    int i(0), j(0), k(0);
    while (i < n && j < m)
    {
        for (j = 0; j < m; j++)
        {
            for (i = 0; i < n; i++)
            {
                if (g[j] == f[i])
                    ff[k++] = g[j];
            }
        }
    }
    for (int i = 0; i < k; cout << ff[i++] << '\t');
    return 0;
}