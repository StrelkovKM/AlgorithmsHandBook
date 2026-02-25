#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    unordered_map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }

    vector<pair<int, int>> items;
    items.reserve(counts.size());
    for (auto const& [val, freq] : counts) {
        items.push_back({val, freq});
    }


    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    vector<int> result = {items[0].first, items[1].first, items[2].first};
    
    sort(result.begin(), result.end());

    cout << result[0] << " " << result[1] << " " << result[2] << endl;

    return 0;
}