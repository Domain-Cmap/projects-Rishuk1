#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<Point> q;
    int freshCount = 0;
    int minutes = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    vector<int> directions = {-1, 0, 1, 0, -1, 0};
    while (!q.empty() && freshCount > 0) {
        int size = q.size();
        minutes++;
        for (int i = 0; i < size; ++i) {
            Point p = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int newX = p.x + directions[d];
                int newY = p.y + directions[d + 1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    freshCount--;
                    q.push({newX, newY});
                }
            }
        }
    }
    return freshCount == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int result = orangesRotting(grid);
    cout << "Minimum minutes: " << result << endl;
    return 0;
}
