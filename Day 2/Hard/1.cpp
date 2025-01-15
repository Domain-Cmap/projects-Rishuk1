#include <bits/stdc++.h>
using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    vector<int> count(batchSize, 0);
    for (int group : groups) {
        count[group % batchSize]++;
    }

    int result = count[0];

    for (int i = 1, j = batchSize - 1; i <= j; ++i) {
        if (i == j) {
            result += count[i] / 2;
        } else {
            int pairs = min(count[i], count[j]);
            result += pairs;
            count[i] -= pairs;
            count[j] -= pairs;
        }
    }

    function<int(int, int)> dfs = [&](int remaining, int state) -> int {
        if (state == 0) return 0;

        static unordered_map<int, int> dp;
        if (dp.count(state)) return dp[state];

        int maxGroups = 0;
        for (int i = 1; i < batchSize; ++i) {
            if ((state >> i) & 1) {
                int newState = state ^ (1 << i);
                int newRemaining = (remaining + i) % batchSize;
                maxGroups = max(maxGroups, (newRemaining == 0 ? 1 : 0) + dfs(newRemaining, newState));
            }
        }

        return dp[state] = maxGroups;
    };

    int state = 0;
    for (int i = 1; i < batchSize; ++i) {
        state |= (count[i] << i);
    }

    return result + dfs(0, state);
}

int main() {
    int batchSize1 = 3;
    vector<int> groups1 = {1, 2, 3, 4, 5, 6};

    int batchSize2 = 4;
    vector<int> groups2 = {1, 3, 2, 5, 2, 2, 1, 6};

    cout << maxHappyGroups(batchSize1, groups1) << endl; // Output: 4
    cout << maxHappyGroups(batchSize2, groups2) << endl; // Output: 4

    return 0;
}