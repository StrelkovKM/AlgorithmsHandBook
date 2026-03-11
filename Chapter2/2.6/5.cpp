#include <iostream>
#include <vector>
#include <queue>

struct Messege {
    int id, freq, begin;

    Messege(const Messege& other) {
        this->id = other.id;
        this->freq = other.freq;
        this->begin = other.begin;
    }

    bool operator>( const Messege& other) {
        return begin > other.begin;
    }

};

int main() {
    std::priority_queue<Messege, std::vector<Messege>, std::greater<Messege>> q;
    int m;

    std::cin >> m;

    while (m <= q.top().begin) {
        std::cout << q.top().id << '\n';
        Messege new_messege = q.top();
        new_messege.begin += new_messege.freq;
        q.pop();
        q.push(new_messege);
    }
}
