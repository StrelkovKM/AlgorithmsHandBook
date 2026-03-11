#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ticket {
    int d, w;
};

bool compareTickets(const Ticket& a, const Ticket& b) {
    if (a.w != b.w) return a.w < b.w;
    return a.d > b.d; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Ticket> tickets(n);
    for (int i = 0; i < n; ++i) {
        cin >> tickets[i].d >> tickets[i].w;
    }

    sort(tickets.begin(), tickets.end(), compareTickets);

    long long t1 = 0, t2 = 0;

    while (!tickets.empty()) {
        Ticket current = tickets.back();
        tickets.pop_back();

        if (t1 <= t2) {
            t1 += current.d;
        } else {
            t2 += current.d;
        }
    }

    cout << max(t1, t2) << endl;

    return 0;
}