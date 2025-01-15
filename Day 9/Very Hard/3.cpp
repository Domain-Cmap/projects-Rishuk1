#include <iostream>
#include <queue>
#include <unordered_set>
#include <tuple>
using namespace std;

int racecar(int target) {
    queue<tuple<int, int, int>> q;  // (position, speed, steps)
    unordered_set<string> visited;
    q.push({0, 1, 0});
    visited.insert("0,1");

    while (!q.empty()) {
        auto [pos, speed, steps] = q.front();
        q.pop();

        if (pos == target) return steps;

        string key = to_string(pos) + "," + to_string(speed);
        if (visited.count(key)) continue;
        visited.insert(key);

        // A (accelerate)
        q.push({pos + speed, speed * 2, steps + 1});

        // R (reverse)
        q.push({pos, (speed > 0) ? -1 : 1, steps + 1});
    }
    return -1;
}

int main() {
    int target = 6;
    cout << "Minimum steps to reach target: " << racecar(target) << endl;
    return 0;
}
