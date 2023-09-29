//Скільки різних букв входить у текст із числом символів не більше 100 й обмеженому крапкою(.).

#include<iostream>      
#include<string.h>      
#include <Windows.h>   

using namespace std;
const int size1 = 101;  

int main() {
    SetConsoleOutputCP(1251);   

    char str[size1] = "";       
    char c_end = '.';          
    char let = 'A';             
    int n = size1 - 1;           
    int i = 0, k = 0, m = 0;                                       
    string s;

    cout << "\nВВЕДІТЬ ТЕКСТ\n";
    cout << "\nВикористовуйте англійські літери.\n";
    cout << "\nПісля введення бажаного тексту введіть « . » та натисніть ENTER\n";
    while (i < n && ((str[i] = getchar()) != c_end)) i++;

    cout << "\nСимволи, що враховуються у статистиці:" << endl;
    for (int i = 0; i < n; i++) {
        if (isupper(str[i])) {
            s += tolower(str[i]);
        }
        else
        {
            if (islower(str[i])) {
                s += str[i];
            }
        }
    }
    cout << s << endl;
   
    while (let <= 'z') {
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == let) {
                m++;
            }
        }
        if (m > 0) {
            k++;
            cout << let << " - " << m << endl;
        }
        let++;
        m = 0;
        i = 0;
    }

    cout << "\nЗагалом використано " << k << " різних літер." << endl;

    return 0;
}