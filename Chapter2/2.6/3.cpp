#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main() {
    // Ускоряем ввод-вывод (критично для больших n)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    // Если k = 0, сумма всегда 0
    if (k <= 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // Min-heap: храним k самых больших элементов, 
    // наверху — самый маленький из "великих".
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;

    long long x;
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> x)) break;

        if (q.size() < k) {
            q.push(x);
        } else if (x > q.top()) {
            q.pop();
            q.push(x);
        }
    }

    unsigned long long sum = 0;
    // Очередь может содержать меньше k элементов, если n < k
    while (!q.empty()) {
        sum += q.top();
        q.pop();
    }

    std::cout << sum << std::endl;

    return 0;
}