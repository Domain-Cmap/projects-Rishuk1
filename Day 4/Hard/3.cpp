#include <bits/stdc++.h>
using namespace std;

class DinnerPlates {
    int capacity;
    set<int> available;
    map<int, stack<int>> stacks;

public:
    DinnerPlates(int capacity) : capacity(capacity) {}

    void push(int val) {
        if (available.empty() || *available.begin() >= stacks.size()) {
            available.insert(stacks.size());
        }

        int idx = *available.begin();
        stacks[idx].push(val);
        if (stacks[idx].size() == capacity) {
            available.erase(idx);
        }
    }

    int pop() {
        while (!stacks.empty() && stacks.rbegin()->second.empty()) {
            stacks.erase(--stacks.end());
        }
        if (stacks.empty()) return -1;

        int idx = stacks.rbegin()->first;
        int val = stacks[idx].top();
        stacks[idx].pop();
        available.insert(idx);

        if (stacks[idx].empty()) {
            stacks.erase(idx);
        }
        return val;
    }

    int popAtStack(int index) {
        if (stacks.find(index) == stacks.end() || stacks[index].empty()) return -1;

        int val = stacks[index].top();
        stacks[index].pop();
        available.insert(index);

        if (stacks[index].empty()) {
            stacks.erase(index);
        }
        return val;
    }
};

int main() {
    DinnerPlates dp(2);
    dp.push(1);
    dp.push(2);
    dp.push(3);
    dp.push(4);
    dp.push(5);
    cout << dp.popAtStack(0) << endl;  // 2
    dp.push(20);
    dp.push(21);
    cout << dp.popAtStack(0) << endl;  // 20
    cout << dp.popAtStack(2) << endl;  // 21
    cout << dp.pop() << endl;          // 5
    cout << dp.pop() << endl;          // 4
    cout << dp.pop() << endl;          // 3
    cout << dp.pop() << endl;          // 1
    cout << dp.pop() << endl;          // -1
    return 0;
}
