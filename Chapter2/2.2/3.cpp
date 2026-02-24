#include <iostream>
#include <vector>
#include <unordered_set>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    std::unordered_set<int> glob;


    int k = 0;
    std::cin >> k;

    for (int j = 0; j < k; j++) {
        int x = 0;
        std::cin >> x;
        glob.insert(x);
    }

    for (int i = 1; i < n; i++) {
        std::unordered_set<int> loc;
        std::cin >> k;
        for(int j = 0; j < k; j++) {
            int x = 0;
            std::cin >> x;
            loc.insert(x);
        }

        std::unordered_set<int> next_glob;
        for (int x : glob) {
            if (loc.count(x)) {
                next_glob.insert(x);
            }
        }
        glob = std::move(next_glob);
    }

    std::cout << glob.size();
}