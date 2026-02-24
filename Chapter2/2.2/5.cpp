#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::unordered_set<int> all_distinct_ors;
    std::vector<int> current_ors;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        std::vector<int> next_ors;
        next_ors.push_back(x);
        all_distinct_ors.insert(x);

        for (int val : current_ors) {
            int new_or = val | x;
            
            if (new_or != next_ors.back()) {
                next_ors.push_back(new_or);
                all_distinct_ors.insert(new_or);
            }
        }
        
        current_ors = std::move(next_ors);
    }

    std::cout << all_distinct_ors.size() << std::endl;

    return 0;
}