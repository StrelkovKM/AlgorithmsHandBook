#include <iostream>
#include <vector>

int Febonachi(std::vector<long long>& mem, int n, int m) {
    if (n <= 1) return n;

    if (n - mem[0] != 0) {
        long long new_num = mem[1] % m + mem[2] % m;
        mem[1] = mem[2];
        mem[2] = new_num;
        mem[0]++;
        return Febonachi(mem, n, m);
    } else {
        return mem[2] % m;
    }
}

int main() {
    std::vector<long long> mem{1, 0, 1};

    int n, m;
    std::cin >> n >> m;
    std::cout << Febonachi(mem, n, m);
}