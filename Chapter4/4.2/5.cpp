#include <iostream>
#include <numeric> // Для std::gcd в C++17
#include <cmath>

long long get_gcd(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    long long a, b, c;
    if (!(std::cin >> a >> b >> c)) return 0;

    // Случай, когда оба коэффициента равны нулю
    if (a == 0 && b == 0) {
        if (c == 0) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
        return 0;
    }

    // Находим НОД(a, b)
    long long g = get_gcd(a, b);

    // Проверяем делимость c на g
    if (c % g == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}