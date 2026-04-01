#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> room(n);
    for (int i = 0; i < n; ++i) {
        cin >> room[i];
    }

    int r, c;
    cin >> r >> c;
    // Переходим к 0-based индексации
    r--; c--;

    int q;
    cin >> q;
    string actions;
    cin >> actions;

    // Направления: 0-вверх, 1-вправо, 2-вниз, 3-влево (по часовой стрелке)
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int dir = 0; // Изначально вверх

    int visited_count = 0;

    // Помечаем стартовую клетку как посещенную
    if (room[r][c] == '.') {
        room[r][c] = 'V';
        visited_count++;
    }

    for (char action : actions) {
        if (action == 'L') {
            dir = (dir + 3) % 4; // Поворот влево (-1 по часовой)
        } else if (action == 'R') {
            dir = (dir + 1) % 4; // Поворот вправо (+1 по часовой)
        } else if (action == 'M') {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            // Проверка границ и препятствий
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && room[nr][nc] != '#') {
                r = nr;
                c = nc;
                // Если клетка еще не была посещена
                if (room[r][c] == '.') {
                    room[r][c] = 'V';
                    visited_count++;
                }
            }
            // Если уперся — просто стоим, ничего не делаем, идем к след. команде
        }
    }

    cout << visited_count << endl;

    return 0;
}