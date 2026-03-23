#include <iostream>

// Используем алгоритм Евклида для поиска GCD
long long gcd(long long x, long long y) {
    while (y) {
        x %= y;
        std::swap(x, y);
    }
    return x;
}

int main() {
    long long a, b, c, d;
    
    // Читаем первую дробь
    if (!(std::cin >> a >> b)) return 0;
    // Читаем вторую дробь
    if (!(std::cin >> c >> d)) return 0;

    // 1. Складываем по правилу: (a*d + c*b) / (b*d)
    long long numerator = a * d + c * b;
    long long denominator = b * d;

    // 2. Находим GCD для сокращения
    long long common = gcd(numerator, denominator);

    // 3. Выводим сокращенную дробь
    std::cout << numerator / common << " " << denominator / common << std::endl;

    return 0;
}