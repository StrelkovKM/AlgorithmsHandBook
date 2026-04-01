#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct State {
    int r, c, k;
};

struct Parent {
    int pr, pc, pk;
    char action;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int sr, sc, fr, fc;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') { sr = i; sc = j; }
            if (grid[i][j] == 'F') { fr = i; fc = j; }
        }
    }

    // dist[row][col][has_key]
    int dist[1000][1000][2];
    Parent parent[1000][1000][2];
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            dist[i][j][0] = dist[i][j][1] = -1;

    queue<State> q;
    q.push({sr, sc, 0});
    dist[sr][sc][0] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    char dchar[] = {'U', 'D', 'R', 'L'};

    int fr_final = -1, fc_final = -1, fk_final = -1;

    while (!q.empty()) {
        State curr = q.front(); q.pop();

        if (curr.r == fr && curr.c == fc) {
            fr_final = curr.r; fc_final = curr.c; fk_final = curr.k;
            break;
        }

        // 1. Попробовать подобрать ключ, если мы на клетке K
        if (grid[curr.r][curr.c] == 'K' && curr.k == 0) {
            if (dist[curr.r][curr.c][1] == -1) {
                dist[curr.r][curr.c][1] = dist[curr.r][curr.c][0] + 1;
                parent[curr.r][curr.c][1] = {curr.r, curr.c, 0, 'P'};
                q.push({curr.r, curr.c, 1});
            }
        }

        // 2. Обычное движение
        for (int i = 0; i < 4; ++i) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#') {
                // Если дверь, нужен ключ
                if (grid[nr][nc] == 'D' && curr.k == 0) continue;

                if (dist[nr][nc][curr.k] == -1) {
                    dist[nr][nc][curr.k] = dist[curr.r][curr.c][curr.k] + 1;
                    parent[nr][nc][curr.k] = {curr.r, curr.c, curr.k, dchar[i]};
                    q.push({nr, nc, curr.k});
                }
            }
        }
    }

    if (fr_final == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[fr_final][fc_final][fk_final] << endl;
        string path = "";
        int cr = fr_final, cc = fc_final, ck = fk_final;
        while (cr != sr || cc != sc || ck != 0) {
            Parent p = parent[cr][cc][ck];
            path += p.action;
            cr = p.pr; cc = p.pc; ck = p.pk;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
    return 0;
}