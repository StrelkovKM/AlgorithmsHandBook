#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

// #######
// #...#.#
// #...#.#
// #.#.#.#
// #.#F#.#
// #....S#
// #######


struct Point {
    int r, c;
};

struct Node {
    int pr, pc;
    char dir;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);

    Point start, finish;

    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'F') {
                finish = {i, j};
            }
        }
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
    std::vector<std::vector<Node>> parent(n, std::vector<Node>(m, {-1, -1, ' '}));
    std::queue<Point> q;

    q.push(start);
    dist[start.r][start.c] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char directions[] = {'U', 'D', 'L', 'R'};

    bool found = false;

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.r == finish.r && curr.c == finish.c) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[curr.r][curr.c] + 1;
                parent[nr][nc] = {curr.r, curr.c, directions[i]};
                q.push({nr, nc});
            }
        }
    }

    if (!found) {
        std::cout << "-1\n";
        return 0;
    } else {
        std::cout << dist[finish.r][finish.c] << "\n";
        std::string path;
        Point curr = finish;
        while (curr.r != start.r || curr.c != start.c) {
            Node p = parent[curr.r][curr.c];
            path += p.dir;
            curr = {p.pr, p.pc};
        }
        std::reverse(path.begin(), path.end());
        std::cout << path << "\n";

    }

    return 0;
}
