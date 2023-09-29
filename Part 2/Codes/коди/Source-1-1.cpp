#include <iostream>
using namespace std;
int w = 3, p = 5, q = 2; //глобальн≥ зм≥нн≥
const int k = 4, a = 5;
const static int n;
void main()
{
	/*ѕам'€ть п≥д глобальн≥ зм≥нн≥ вид≥л€Їтьс€ посл≥довно*/
	cout << "w = " << w << "\t&w = " << &w << endl;
	cout << "p = " << p << "\t&p = " << &p << endl;
	cout << "q = " << q << "\t&q = " << &q << endl;
	/*јдреси зм≥нних w,p,q в≥др≥зн€ютьс€ на 4 байти*/
	cout << "\nk = " << k << "\t&k = " << &k << endl;
	cout << "a = " << a << "\t&a = " << &a << endl;
	cout << "n = " << n << "\t&n = " << &n << endl;
	/*ѕам€ть п≥д по≥менован≥ коснтанти вид≥лено в ≥ншому
	сегмент≥, але також посл≥довно*/
}