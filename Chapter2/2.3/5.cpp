#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> word_counts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        word_counts[s]++;
    }

    long long total_pairs = 0;
    int word_len = word_counts.begin()->first.length();

    // Цикл по каждой позиции символа
    for (int i = 0; i < word_len; ++i) {
        unordered_map<string, long long> masks;
        
        for (auto const& [word, count] : word_counts) {
            string mask = word;
            mask[i] = '*';
            masks[mask] += count;
        }

        for (auto const& [mask, k] : masks) {
            total_pairs += (k * (k - 1) / 2);
        }
    }

    // Вычитаем одинаковые слова
    long long same_word_pairs = 0;
    for (auto const& [word, count] : word_counts) {
        long long c = count;
        same_word_pairs += (c * (c - 1) / 2);
    }

    cout << total_pairs - (same_word_pairs * word_len) << endl;

    return 0;
}