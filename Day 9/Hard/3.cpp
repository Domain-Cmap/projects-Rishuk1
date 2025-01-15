#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m-1][n] = dp[m][n-1] = 1;

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int min_health_needed = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] = max(min_health_needed, 1);
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << "Initial health: " << calculateMinimumHP(dungeon) << endl;
    return 0;
}
