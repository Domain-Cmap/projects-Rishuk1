#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingPathHelper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (dp[i][j] != -1) return dp[i][j];

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int longestPath = 1;

    for (auto& dir : directions) {
        int newI = i + dir.first, newJ = j + dir.second;

        if (newI >= 0 && newI < matrix.size() && newJ >= 0 && newJ < matrix[0].size() && matrix[newI][newJ] > matrix[i][j]) {
            longestPath = max(longestPath, 1 + longestIncreasingPathHelper(newI, newJ, matrix, dp));
        }
    }

    dp[i][j] = longestPath;
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int maxPath = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            maxPath = max(maxPath, longestIncreasingPathHelper(i, j, matrix, dp));
        }
    }

    return maxPath;
}

int main() {
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << "Longest Increasing Path: " << longestIncreasingPath(matrix) << endl;
    return 0;
}
