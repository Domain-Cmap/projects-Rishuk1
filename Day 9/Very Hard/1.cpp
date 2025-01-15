#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cherryPickupHelper(int r1, int c1, int r2, int c2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
    if (r1 < 0 || r1 >= grid.size() || c1 < 0 || c1 >= grid[0].size() || r2 < 0 || r2 >= grid.size() || c2 < 0 || c2 >= grid[0].size()) return -1;
    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1;
    if (r1 == grid.size() - 1 && c1 == grid[0].size() - 1 && r2 == grid.size() - 1 && c2 == grid[0].size() - 1) {
        return grid[r1][c1] + grid[r2][c2];
    }
    if (dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

    int cherries = grid[r1][c1] + (r1 != r2 || c1 != c2 ? grid[r2][c2] : 0);
    grid[r1][c1] = grid[r2][c2] = 0; // Avoid counting cherries twice

    int res = max({cherryPickupHelper(r1 + 1, c1, r2 + 1, c2, grid, dp),
                   cherryPickupHelper(r1 + 1, c1, r2, c2 + 1, grid, dp),
                   cherryPickupHelper(r1, c1 + 1, r2 + 1, c2, grid, dp),
                   cherryPickupHelper(r1, c1 + 1, r2, c2 + 1, grid, dp)});
    
    grid[r1][c1] = grid[r2][c2] = cherries; // Restore grid state
    return dp[r1][c1][r2][c2] = (res == -1 ? -1 : res + cherries);
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
    return max(0, cherryPickupHelper(0, 0, 0, 0, grid, dp));
}

int main() {
    vector<vector<int>> grid = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    cout << "Maximum cherries picked: " << cherryPickup(grid) << endl;
    return 0;
}
