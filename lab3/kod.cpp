#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001); 

    double a = 0.1;            
    double b = 1.0;            
    int k = 10;                
    double h = (b - a) / k;    
    double eps = 0.0001;       
    int N = 10;                

    cout << fixed << setprecision(6);
    cout << "--------------------------------------------------------\n";
    cout << "|    X    |    SN    |    SE    |    Y    |\n";
    cout << "--------------------------------------------------------\n";

    for (double x = a; x <= b + h / 2.0; x += h)
    {
        
        double SN = 1.0;       
        double an = x * x;     
        an = 3.0 * x * x;      

        for (int n = 1; n <= N; n++)
        {
            SN += an;
            
            an = an * (x * x) * (2.0 * n + 3) / ((n + 1) * (2.0 * n + 1));
        }

       
        double SE = 1.0;      
        double ae = 3.0 * x * x; 
        int n_eps = 1;

        while (ae >= eps)
        {
            SE += ae;
            n_eps++;
            ae = ae * (x * x) * (2.0 * n_eps + 1) / (n_eps * (2.0 * n_eps - 1));
        }

       
        double y = (1.0 + 2.0 * x * x) * exp(x * x);

       
        cout << "| " << setw(7) << x 
             << " | " << setw(8) << SN 
             << " | " << setw(8) << SE 
             << " | " << setw(7) << y << " |\n";
    }

    return 0;
}