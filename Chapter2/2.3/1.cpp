#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::unordered_map<int, int> data;
    data.reserve(n); 

    for(int i = 0; i < n; ++i) {
        int type, key;
        std::cin >> type >> key;

        if (type == 1) {
            int value;
            std::cin >> value;
            data[key] = value;
        } else {
            auto it = data.find(key);
            if (it != data.end()) {
                std::cout << it->second << '\n';
            } else {
                std::cout << "-1\n";
            }
        }
    }

    return 0;
}