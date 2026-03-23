#include <iostream>
#include <vector>

int main() {
    long long n;
    if (!(std::cin >> n)) return 0;

    // Особые случаи для очень маленьких n
    if (n == 0) {
        std::cout << "0 0" << std::endl;
        return 0;
    }
    if (n == 1) {
        // GCD(1, 1) даст 2 вызова: (1,1) -> (1,0)
        // GCD(0, 1) даст 1 вызов: (0,1)
        std::cout << "1 1" << std::endl;
        return 0;
    }

    long long f_prev = 1; // F_2
    long long f_curr = 2; // F_3

    // Мы ищем два последовательных числа Фибоначчи F_k и F_{k+1},
    // такие что F_{k+1} <= n.
    // Это гарантирует максимальное количество делений.
    while (f_prev + f_curr <= n) {
        long long next = f_prev + f_curr;
        f_prev = f_curr;
        f_curr = next;
    }

    // В примере для n=10 вывод 5 8.
    // В примере для n=3 вывод 2 3.
    // Мой алгоритм: для n=10 выдаст 5 8, для n=3 выдаст 2 3.
    std::cout << f_prev << " " << f_curr << std::endl;

    return 0;
}