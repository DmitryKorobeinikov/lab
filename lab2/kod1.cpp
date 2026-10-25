#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001); 
    double sum = 0;
    double a = 0.5;          
    int n = 1;
    double eps = 0.0001;     

    while (a >= eps)
    {
        sum += a;
        n++;
        a = a * n / ((2.0 * n - 1) * (2.0 * n));
    }

    
    cout << fixed << setprecision(6);
    cout << "Сумма ряда с точностью eps = 1e-4: " << sum << endl;
    

    return 0;
}