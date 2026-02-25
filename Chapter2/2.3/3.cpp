#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long ll;

int GCD(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

struct pair_hash {
    inline size_t operator()(const std::pair<int, int> & v) const {
        return std::hash<int>()(v.first) ^ (std::hash<int>()(v.second) << 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL);
    int n = 0;
    std::cin >> n;

    std::unordered_map<std::pair<int, int>, int, pair_hash> frac;

    for (int i = 0; i < n; i++) {
        int num, dim;
        std::cin >> num >> dim;
        int gcd = GCD(num, dim);
        num /= gcd;
        dim /= gcd;
        frac[std::pair<int, int> {num, dim}]++;
    }

    int max_count = -1;
    std::pair<int, int> min_pair {1001, 1};

    for (const auto& f : frac) {
        const auto& current_frac = f.first;
        int current_count = f.second;

        if (current_count > max_count) {
            max_count = current_count;
            min_pair = current_frac;
        } 
        else if (current_count == max_count) {
            if ((ll)current_frac.first * min_pair.second < (ll)min_pair.first * current_frac.second) {
                min_pair = current_frac;
            }
        }
    }
    std::cout << min_pair.first << ' ' << min_pair.second;
}