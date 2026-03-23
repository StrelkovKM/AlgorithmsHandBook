#include <iostream>
#include <vector>

// Функция для поиска длины периода Пизано по модулю m
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        // Период Пизано всегда начинается с 0, 1
        if (a == 0 && b == 1) return i + 1;
    }
    return 0;
}

// Быстрое вычисление F(n) % m
long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1) return n;

    long long prev = 0;
    long long curr = 1;

    for (long long i = 0; i < n - 1; i++) {
        long long tmp_prev = prev;
        prev = curr;
        curr = (tmp_prev + curr) % m;
    }

    return curr;
}

int main() {
    long long n, m;
    if (!(std::cin >> n >> m)) return 0;

    // 1. Находим период повторения для модуля m
    long long period = get_pisano_period(m);
    
    // 2. Сокращаем n с помощью периода
    n %= period;

    // 3. Считаем остаток обычным циклом (безопасно для стека)
    std::cout << get_fibonacci_huge(n, m) << std::endl;

    return 0;
}