#include <iostream>
#include <queue>
#include <vector>
#include <utility>

int main() {
    int n, k, count = 0;
    std::cin >> n >> k;
    auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> w(cmp);

    for (int i = 0; i < k; i++) {
        int a_i, b_i;
        std::cin >> a_i >> b_i;
        w.push(std::pair<int, int> (a_i, b_i));
        count++;
    }

    for (int i = k; i < n; i++) {
        int a_i, b_i;
        std::cin >> a_i >> b_i;

        while (w.top().second <= a_i) {
            w.pop();
        }

        if (w.size() != k) {
            w.push(std::pair<int, int> (a_i, b_i));
            count++;
        }
    }

    std::cout << count;
}