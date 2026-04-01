#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Ускоряем ввод-вывод для больших n
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Матрицы смежности (n+1 x n+1), инициализированные нулями
    vector<vector<int>> g1(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> g2(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<int> route(k);
        for (int j = 0; j < k; ++j) {
            cin >> route[j];
        }

        // Заполнение первого графа (только соседи)
        for (int j = 0; j < k - 1; ++j) {
            int u = route[j];
            int v = route[j + 1];
            if (u != v) {
                g1[u][v] = g1[v][u] = 1;
            }
        }

        // Заполнение второго графа (все пары в одном маршруте)
        for (int j = 0; j < k; ++j) {
            for (int l = j + 1; l < k; ++l) {
                int u = route[j];
                int v = route[l];
                if (u != v) {
                    g2[u][v] = g2[v][u] = 1;
                }
            }
        }
    }

    // Вывод первой матрицы
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << g1[i][j] << (j == n ? "" : " ");
        }
        cout << "\n";
    }

    // Вывод второй матрицы
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << g2[i][j] << (j == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}