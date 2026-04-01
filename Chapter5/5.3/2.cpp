#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>


const int MAX_VAL = 200000;

int main() {
    int X, Y;
    std::cin >> X >> Y;

    if (X == Y) {
        std::cout << "0\n";
        return 0;
    }

    std::vector<int> dist(MAX_VAL + 1, -1);
    std::queue<int> q;

    q.push(X);
    dist[X] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int c = 0; c <= 9; c++) {
            int next_options[3] = {u + c, u - c, u * c};

            for (int v : next_options) {
                if (v >= 0 && v <= MAX_VAL && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);

                    if (v == Y) {
                        std::cout << dist[v] << "\n";
                        return 0;
                    }
                }
            }
        }
    }
}