#include <iostream>
#include <cstdarg>
#include <numeric> // для НОД

using namespace std;

// --- Структура для обыкновенной дроби ---
struct Fraction {
    int num, den;
};

// Упрощение дроби
Fraction simplify(Fraction f) {
    int n = f.num, d = f.den;
    while (d != 0) { int t = d; d = n % d; n = t; }
    return {f.num / n, f.den / n};
}

// --- 7.1. Перегруженные функции умножения ---
double multiply(double a, double b) {
    return a * b;
}

Fraction multiply(Fraction a, Fraction b) {
    return simplify({a.num * b.num, a.den * b.den});
}

// --- 7.2. Функция с переменным числом параметров ---
// Принимаем пары int (числитель, знаменатель)
Fraction sumFractions(int count, ...) {
    va_list args;
    va_start(args, count);
    
    Fraction res = {0, 1}; // Начальная сумма = 0/1
    
    for (int i = 0; i < count; ++i) {
        int n = va_arg(args, int);
        int d = va_arg(args, int);
        // res = res + n/d => (res.num * d + n * res.den) / (res.den * d)
        res.num = res.num * d + n * res.den;
        res.den = res.den * d;
        res = simplify(res);
    }
    
    va_end(args);
    return res;
}

void printFraction(Fraction f) {
    cout << f.num << "/" << f.den;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "--- Лабораторная 7.1 (Перегрузка) ---\n";
    double d1 = 2.5, d2 = 4.0;
    cout << "Умножение десятичных: " << d1 << " * " << d2 << " = " << multiply(d1, d2) << "\n";
    
    Fraction f1 = {1, 2}, f2 = {3, 4};
    cout << "Умножение обыкновенных: 1/2 * 3/4 = ";
    printFraction(multiply(f1, f2));
    cout << "\n\n";

    cout << "--- Лабораторная 7.2 (Переменное число параметров) ---\n";
    
    // Сумма 5 дробей: 1/2 + 1/3 + 1/4 + 1/5 + 1/6
    cout << "Сумма 5 дробей: ";
    printFraction(sumFractions(5, 1,2, 1,3, 1,4, 1,5, 1,6));
    cout << "\n";

    // Сумма 10 дробей (все 1/10)
    cout << "Сумма 10 дробей (10 раз по 1/10): ";
    printFraction(sumFractions(10, 1,10, 1,10, 1,10, 1,10, 1,10, 1,10, 1,10, 1,10, 1,10, 1,10));
    cout << "\n";

    // Сумма 12 дробей
    cout << "Сумма 12 дробей (12 раз по 1/12): ";
    printFraction(sumFractions(12, 1,12, 1,12, 1,12, 1,12, 1,12, 1,12, 1,12, 1,12, 1,12, 1,12, 1,12, 1,12));
    cout << "\n";

    return 0;
}