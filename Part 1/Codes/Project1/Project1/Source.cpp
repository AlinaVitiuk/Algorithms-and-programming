#include <iostream>
using namespace std;
void main()
{
	unsigned char i = 1;
	for (int j = 1; j <= 127; j++)
		i++;
	cout << "\n i = " << i << "\n";
}