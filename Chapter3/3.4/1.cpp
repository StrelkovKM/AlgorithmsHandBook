#include <iostream>


int GCD(int a, int b) {
    while ( b > 0 && a > 0 ) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a + b;
}

int main() {
    int a, b;
    if (!(std::cin >> a >> b)) return 0;

    std::cout << GCD(a, b) << std::endl;

    return 0;
}