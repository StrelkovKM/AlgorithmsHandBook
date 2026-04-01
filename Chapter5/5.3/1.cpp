#include <iostream>
#include <vector>
#include <string>
#include <queue>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> in_degree(n + 1, 0);


    for (int i = 0; i < m; ++i) {
        int u_i, v_i, t_i;
        std::cin >> u_i >> v_i >> t_i;
        int winner = (t_i == 1) ? u_i : v_i;
        int loser = (t_i == 1) ? v_i : u_i;
        adj[winner].push_back(loser);
        in_degree[loser]++;
    }

    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int visited_count = 0;
    bool unique = true;

    while (!q.empty()) {
        if (q.size() > 1) {
            unique = false;
        }
        int u = q.front();
        q.pop();
        visited_count++;

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (visited_count == n) {
        std::cout << (unique ? "YES" : "NO") << "\n";
    } else {
        std::cout << "NO\n";
    }
}