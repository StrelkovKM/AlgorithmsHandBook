#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> set_sizes(n);
    std::unordered_map<int, int> counts;
    counts.reserve(200000); 

    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        set_sizes[i] = k;
        for (int j = 0; j < k; ++j) {
            int x;
            std::cin >> x;
            counts[x]++;
        }
    }

    int core_size = 0;
    for (auto const& [val, count] : counts) {
        if (count == n) {
            core_size++;
        } else if (count > 1) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << "\n";
    std::cout << core_size << "\n";

    for (int i = 0; i < n; ++i) {
        std::cout << set_sizes[i] - core_size << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}