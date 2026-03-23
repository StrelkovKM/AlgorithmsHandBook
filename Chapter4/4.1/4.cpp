#include <iostream>

long long get_fibonacci_last_digit(long long n) {
    if (n <= 1) return n;

    // Период Пизано для m=10 равен 60
    n %= 60; 
    if (n == 0) return 0;

    long long prev = 0;
    long long curr = 1;

    for (long long i = 0; i < n - 1; i++) {
        long long tmp_prev = prev;
        prev = curr;
        curr = (tmp_prev + curr) % 10;
    }

    return curr;
}

int main() {
    long long n;
    if (!(std::cin >> n)) return 0;

    // Сумма F_0 + ... + F_n = F_{n+2} - 1
    // Ищем последнюю цифру F_{n+2}
    long long last_digit_fn2 = get_fibonacci_last_digit(n + 2);

    // Вычисляем (last_digit - 1), учитывая, что результат должен быть 0..9
    // Добавляем 10, чтобы избежать отрицательных чисел (например, если last_digit был 0)
    int result = (last_digit_fn2 - 1 + 10) % 10;

    std::cout << result << std::endl;

    return 0;
}