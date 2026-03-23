#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    // 1. Генерируем числа Фибоначчи (1, 2, 3, 5, 8, 13...)
    // F1 = 1, F2 = 2 (пропускаем дублирующуюся единицу)
    vector<long long> fibs;
    fibs.push_back(1);
    fibs.push_back(2);
    
    while (true) {
        long long next_fib = fibs[fibs.size() - 1] + fibs[fibs.size() - 2];
        if (next_fib > n) break;
        fibs.push_back(next_fib);
    }

    // 2. Жадный алгоритм: идем с конца списка чисел Фибоначчи
    string result = "";
    for (int i = fibs.size() - 1; i >= 0; i--) {
        if (n >= fibs[i]) {
            result += '1';
            n -= fibs[i];
        } else {
            result += '0';
        }
    }

    cout << result << endl;

    return 0;
}