#include <iostream>
#include <vector>
#include <unordered_set>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::unordered_set<int> s;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int k = 0;
        std::cin >> k;
        for(int j = 0; j < k; j++) {
            int x = 0;
            std::cin >> x;
            s.insert(x);
        }
    }

    std::cout << s.size();
}