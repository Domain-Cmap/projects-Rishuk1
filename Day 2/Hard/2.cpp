#include <bits/stdc++.h>
using namespace std;

int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

    dp[0][0][cols - 1] = grid[0][0] + (0 == cols - 1 ? 0 : grid[0][cols - 1]);

    for (int r = 1; r < rows; ++r) {
        vector<vector<int>> newDp(cols, vector<int>(cols, -1));
        for (int c1 = 0; c1 < cols; ++c1) {
            for (int c2 = 0; c2 < cols; ++c2) {
                if (dp[r - 1][c1][c2] != -1) {
                    for (int d1 = -1; d1 <= 1; ++d1) {
                        for (int d2 = -1; d2 <= 1; ++d2) {
                            int nc1 = c1 + d1, nc2 = c2 + d2;
                            if (nc1 >= 0 && nc1 < cols && nc2 >= 0 && nc2 < cols) {
                                int cherries = grid[r][nc1] + (nc1 == nc2 ? 0 : grid[r][nc2]);
                                newDp[nc1][nc2] = max(newDp[nc1][nc2], dp[r - 1][c1][c2] + cherries);
                            }
                        }
                    }
                }
            }
        }
        dp[r] = newDp;
    }

    int result = 0;
    for (int c1 = 0; c1 < cols; ++c1) {
        for (int c2 = 0; c2 < cols; ++c2) {
            result = max(result, dp[rows - 1][c1][c2]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> grid1 = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 0, 0, 0, 0, 0, 1},
        {2, 0, 0, 0, 0, 3, 0},
        {2, 0, 9, 0, 0, 0, 0},
        {0, 3, 0, 5, 4, 0, 0},
        {1, 0, 2, 3, 0, 0, 6}
    };

    cout << cherryPickup(grid1) << endl; // Output: 24
    cout << cherryPickup(grid2) << endl; // Output: 28

    return 0;
}