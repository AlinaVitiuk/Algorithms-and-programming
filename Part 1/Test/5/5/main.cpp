#include<iostream>

float funk(float x);
int len(float min, float max, float h);
float poldil(float precision, float min, float max);

int main() {
    // setlocale(LC_ALL,"Ukrainian");
    // довжина кроку, початок відліку, кінець відліку, точність кореня
    float h = 1, num1 = -10, num2 = 10, precision = 0.001;

    int a = 0;
    float result[leng], mas1[leng], mas2[leng];

    while (num1 <= num2) {
        if (funk(num1) * funk(num1 + h) <= 0) {
            mas1[a] = num1;
            mas2[a] = num1 + h;
            result[a] = poldil(precision, num1, num1 + h);
            a++;
        }
        num1 += h;
    }
    for (int i; i < leng; i++)printf("Korin: %f, Vidrizok: %f - %f\n", result[i], mas1[i], mas2[i]);

    return 0;
}

float poldil(float precision, float min, float max) {
    float a = min, c = max, b;

    do {
        b = (a + c) / 2;
        if (funk(b) == 0)return b;
        if (funk(a) == 0)return a;
        if (funk(c) == 0)return c;
        if (funk(a) * funk(b) < 0)c = b;
        if (funk(c) * funk(b) < 0)a = b;

    } while (funk(b) != precision);
    return b;
}

// кількість відповідей
int len(float min, float max, float h) {
    int num = 0;
    float nul = max;

    for (float i = min; i <= max; i += h) {
        if (funk(i) * funk(i + h) <= 0)num++;
    }
    return num;
}

// тут функція
float funk(float x) {
    return x * x - 1;
}