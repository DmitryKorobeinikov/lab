#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int** createArray(int rows, int cols) {
    int** arr = new (nothrow) int*[rows];
    if (arr == nullptr) {
        cout << "Ошибка выделения памяти под массив указателей!\n";
        return nullptr;
    }
    
    for (int i = 0; i < rows; i++) {
        arr[i] = new (nothrow) int[cols];
        
        // Если не удалось выделить память для одной из строк
        if (arr[i] == nullptr) {
            cout << "Ошибка выделения памяти под строку " << i << "!\n";
            // Очищаем то, что уже успели выделить
            for (int j = 0; j < i; j++) {
                delete[] arr[j];
            }
            delete[] arr;
            return nullptr;
        }
    }
    
    return arr; // ОБЯЗАТЕЛЬНО возвращаем созданный массив
}

void fillArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void deleteArray(int** arr, int rows) {
    if (arr == nullptr) return; // Используем nullptr вместо NULL
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned int>(time(NULL)));
    
    int N, M;
    
    cout << "Введите количество строк N: ";
    cin >> N;
    cout << "Введите количество столбцов M: ";
    cin >> M;
    
    if (N <= 0 || M <= 0) {
        cout << "Размеры должны быть положительными!\n";
        return 1;
    }
    
    int** arr = createArray(N, M);
    if (arr == nullptr) { // ДОБАВЛЕНА ПРОВЕРКА
        return 1;
    }
    
    fillArray(arr, N, M);
    
    cout << "\nИсходный массив " << N << "x" << M << endl;
    printArray(arr, N, M);
    
    int rowAdd, colAdd;
    cout << "\nВведите номер строки для добавления (0-" << N << "): ";
    cin >> rowAdd;
    cout << "Введите номер столбца для добавления (0-" << M << "): ";
    cin >> colAdd;
    
    if (rowAdd < 0 || rowAdd > N || colAdd < 0 || colAdd > M) {
        cout << "Некорректные номера!\n";
        deleteArray(arr, N);
        return 1;
    }
    
    // Создание нового массива
    int** newArr = createArray(N + 1, M + 1);
    if (newArr == nullptr) {
        deleteArray(arr, N);
        return 1;
    }
    
    // Копирование данных и вставка нулей
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            if (i == rowAdd) {
                newArr[i][j] = 0; // Новая строка заполняется нулями
            } else if (j == colAdd) {
                newArr[i][j] = 0; // Новый столбец заполняется нулями
            } else {
                int srcRow = (i < rowAdd) ? i : i - 1;
                int srcCol = (j < colAdd) ? j : j - 1;
                newArr[i][j] = arr[srcRow][srcCol];
            }
        }
    }
    
    cout << "\nНовый массив " << (N + 1) << "x" << (M + 1) << endl;
    printArray(newArr, N + 1, M + 1);
    
    // Освобождение памяти
    deleteArray(arr, N);
    deleteArray(newArr, N + 1);
    
    cout << "\nПамять освобождена\n";
    return 0;
}