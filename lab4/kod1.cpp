#include <iostream>
#include <stdlib.h>  

#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001); 
    srand(time(0));         

    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 10;            

   
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 90 + 10; 
    }

    
    cout << "Исходный массив (10 элементов):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    size -= 5;
    
    cout << "После удаления 5 последних элементов:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    for (int i = size - 1; i >= 0; i--) {
        arr[i + 3] = arr[i];
    }
    size += 3; 

    
    for (int i = 2; i >= 0; i--) {
        arr[i] = arr[i + 1] + 2;
    }

   
    cout << "Итоговый массив (после добавления 3 элементов в начало):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}