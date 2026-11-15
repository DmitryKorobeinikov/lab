#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <windows.h>

using namespace std;

bool isOnlyDigits(const string& s) {
    for (char c : s) if (!isdigit(c)) return false;
    return true;
}

bool isOnlyLetters(const string& s) {
    for (char c : s) if (!isalpha(c)) return false;
    return true;
}

int main() {
    SetConsoleOutputCP(65001);
    string input;
    cout << "Введите строку (с точкой в конце):\n";
    getline(cin, input);

    // Удаляем точку в конце, если она есть
    if (!input.empty() && input.back() == '.') input.pop_back();

    vector<string> digits, letters, mixed;
    stringstream ss(input);
    string word;

    while (ss >> word) {
        if (isOnlyDigits(word)) digits.push_back(word);
        else if (isOnlyLetters(word)) letters.push_back(word);
        else mixed.push_back(word);
    }

    cout << "\nРезультат:\n";
    bool first = true;
    auto printVec = [&](const vector<string>& vec) {
        for (const string& w : vec) {
            if (!first) cout << " ";
            cout << w;
            first = false;
        }
    };

    printVec(digits);
    printVec(letters);
    printVec(mixed);
    cout << ".\n";

    return 0;
}