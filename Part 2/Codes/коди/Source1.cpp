#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

const int i = 0;
const int n = 1;
const int mult = n * i;
int main()
{

    const double pi = 3.141592653589793;
    float e = 0.001;
    float x = pi / 4;

    int funk = fabs(sin(x) - x * (1 - (pow(((x) / (i * pi)), 2));

    if (mult >= e)
    {
        funk == e;
    }

    while (fabs(sin(x) - x * (1 - (pow(((x) / (i * pi)), 2)) >= e)
    {
        n = i;
        i++;
    }

    cout << setprecision(10) << funk;
    cout << i << endl;
    return 0
}