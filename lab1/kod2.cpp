#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    int n = 5, m = 3;

    cout << "=== Задание 2 ===" << endl;
    cout << "Начальные значения: n = " << n << ", m = " << m << endl;

    // Выражение 1: n++ * m
    int r1 = n++ * m;
    cout << "\n1) n++ * m" << endl;
    cout << "   Результат = " << r1 << endl;
    cout << "   n после операции = " << n << endl;

    // Выражение 2: n++ < m
    int r2 = n++ < m;
    cout << "\n2) n++ < m" << endl;
    cout << "   Результат = " << r2 << " (0 - ложь, 1 - истина)" << endl;
    cout << "   n после операции = " << n << endl;

    // Выражение 3: m-- > m
    cout << "\n3) m-- > m" << endl;
    m = 3;
    int r3 = m-- > m;
    cout << "   Результат на данном компиляторе = " << r3 << endl;
    cout << "   m после операции = " << m << endl;

    return 0;
}