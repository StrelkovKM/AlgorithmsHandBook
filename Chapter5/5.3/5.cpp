#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct State {
    int r, c, mask;
};

struct Node {
    int pr, pc, pm;
    char act;
};

int main() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    int sr, sc, fr, fc;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') { sr = i; sc = j; }
            if (grid[i][j] == 'F') { fr = i; fc = j; }
        }
    }

    int k; cin >> k;
    map<char, int> key_to_bit;
    map<char, int> door_to_bit;
    for (int i = 0; i < k; ++i) {
        char d, ky; cin >> d >> ky;
        key_to_bit[ky] = i;
        door_to_bit[d] = i;
    }

    static int dist[100][100][1024]; 
    static Node parent[100][100][1024];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) for(int s=0; s<(1<<k); s++) dist[i][j][s] = -1;

    queue<State> q;
    q.push({sr, sc, 0});
    dist[sr][sc][0] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    char dchar[] = {'U', 'D', 'R', 'L'};

    while (!q.empty()) {
        State curr = q.front(); q.pop();

        if (curr.r == fr && curr.c == fc) {
            return 0;
        }
        char cell = grid[curr.r][curr.c];
        if (key_to_bit.count(cell)) {
            int bit = key_to_bit[cell];
            if (!(curr.mask & (1 << bit))) {
                int nm = curr.mask | (1 << bit);
                if (dist[curr.r][curr.c][nm] == -1) {
                    dist[curr.r][curr.c][nm] = dist[curr.r][curr.c][curr.mask] + 1;
                    parent[curr.r][curr.c][nm] = {curr.r, curr.c, curr.mask, 'P'};
                    q.push({curr.r, curr.c, nm});
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '#') continue;

            char ncell = grid[nr][nc];
            if (door_to_bit.count(ncell)) {
                int bit = door_to_bit[ncell];
                if (!(curr.mask & (1 << bit))) continue; 
            }

            if (dist[nr][nc][curr.mask] == -1) {
                dist[nr][nc][curr.mask] = dist[curr.r][curr.c][curr.mask] + 1;
                parent[nr][nc][curr.mask] = {curr.r, curr.c, curr.mask, dchar[i]};
                q.push({nr, nc, curr.mask});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}