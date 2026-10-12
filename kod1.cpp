#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    double a = 1000.0;
    double b = 0.001;

    // Расчёт для типа float 
    float af = 1000.0f;
    float bf = 0.001f;

    float c1 = pow(af - bf, 4);           // (a - b)^4
    float c2 = pow(af, 4);                // a^4
    float c3 = 4.0f * pow(af, 3) * bf;    // 4a^3 * b
    float c4 = 6.0f * af * af * bf * bf;  // 6a^2 * b^2
    float c5 = 4.0f * af * bf * bf * bf;  // 4a * b^3
    float c6 = bf * bf * bf * bf;         // b^4

    float num_f = c1 - (c2 - c3);         // числитель
    float den_f = c4 - c5 + c6;           // знаменатель
    float yf = num_f / den_f;

    // Расчёт для типа double
    double d1 = pow(a - b, 4);            // (a - b)^4
    double d2 = pow(a, 4);                // a^4
    double d3 = 4.0 * pow(a, 3) * b;      // 4a^3 * b
    double d4 = 6.0 * a * a * b * b;      // 6a^2 * b^2
    double d5 = 4.0 * a * b * b * b;      // 4a * b^3
    double d6 = b * b * b * b;            // b^4

    double num_d = d1 - (d2 - d3);        // числитель
    double den_d = d4 - d5 + d6;          // знаменатель
    double yd = num_d / den_d;

    //  Вывод результатов 
    cout << fixed << setprecision(6);
    cout << "=== Задание 1 ===" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    cout << "Результат (float)  y = " << yf << endl;
    cout << "Результат (double) y = " << yd << endl;

    cout << "Точный ответ (математически): y = 1.0" << endl;
    cout << "Отклонение float  от 1: " << fabs(yf - 1.0) << endl;
    cout << "Отклонение double от 1: " << fabs(yd - 1.0) << endl;

    return 0;
}