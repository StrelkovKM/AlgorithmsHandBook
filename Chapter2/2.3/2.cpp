#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n = 0;
    std::cin >> n;

    std::vector<int> counter(100001, 0);

    for(int i = 0; i < n; i++) {
        int m = 0;
        std::cin >> m; 
        counter[m]++;
    }

    int idx = -1;
    int max = -1;

    for(int i = 0; i < 100001; i++) {
        if (counter[i] > max) {
            max = counter[i];
            idx = i;
        }
    }

    std::cout << idx;
}