#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // Initialize the queue with all the 0s and set their distances to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 0 && newX < m && newY >= 0 && newY < n && dist[newX][newY] == -1) {
                dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }
    return dist;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m): "; cin >> m;
    cout << "Enter the number of columns (n): "; cin >> n;
    
    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the matrix elements (0 or 1):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> result = updateMatrix(mat);

    cout << "Updated Matrix with distances to nearest 0:\n";
    for (auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
