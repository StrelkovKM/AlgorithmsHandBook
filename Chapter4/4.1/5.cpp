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
    long long n, m;
    if (!(std::cin >> m >> n)) return 0;

    long long last_digit_n = get_fibonacci_last_digit(n + 2);
    long long last_digit_m = get_fibonacci_last_digit(m + 1);
    int result = (last_digit_n - last_digit_m + 10) % 10;

    std::cout << result << std::endl;

    return 0;
}