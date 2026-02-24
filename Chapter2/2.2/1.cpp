#include <set>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int q = 0;
    std::cin >> q;

    std::set<int> s;

    for(int i = 0; i < q; i++) {
        int re = 0, x = 0;
        std::cin >> re >> x;
        if (re == 1) s.insert(x);
        else if (re == 2) std::cout << s.count(x) << '\n';
    }
}