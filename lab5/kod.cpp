#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

int checkOrder(int row[], int size) {
    bool isAsc = true, isDesc = true;
    for (int i = 0; i < size - 1; i++) {
        if (row[i] > row[i + 1]) isAsc = false;
        if (row[i] < row[i + 1]) isDesc = false;
    }
    if (isAsc) return 1;
    if (isDesc) return -1;
    return 0;
}

void sortAscending(int row[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (row[j] > row[j + 1]) swap(row[j], row[j + 1]);
}

void printMatrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) cout << matrix[i][j] << "\t";
        cout << "\n";
    }
}

int main() {
    SetConsoleOutputCP(65001);
    int matrix[ROWS][COLS] = {
        {9, 7, 5, 3}, // По убыванию
        {1, 2, 3, 4}, // По возрастанию
        {5, 1, 9, 2}  // Не упорядочена
    };
    
    cout << "Исходная матрица:\n";
    printMatrix(matrix);
    
    for (int i = 0; i < ROWS; i++) {
        if (checkOrder(matrix[i], COLS) != -1) {
            sortAscending(matrix[i], COLS);
        }
    }
    
    cout << "\nМатрица после обработки:\n";
    printMatrix(matrix);
    return 0;
}