#include <iostream>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int> pq;
    int n;

    if (!(std::cin >> n)) return 0;
    for (int i = 0; i < n; ++i) {
        int q;
        std::cin >> q;
        if (q == 1) {
            int x;
            std::cin >> x;
            pq.push(x);
        } else if (q == 2 && !pq.empty()) {
            pq.pop();
        }
        if (pq.empty()) {
            std::cout << -1 << "\n";
        } else {
            std::cout << pq.top() << "\n";
        }
    }
}
