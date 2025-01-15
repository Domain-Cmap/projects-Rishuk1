#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findPaths(vector<vector<int>>& maze, int x, int y, vector<vector<bool>>& visited, 
                vector<string>& path, string currentPath) {
    int n = maze.size(), m = maze[0].size();
    if (x == n - 1 && y == m - 1) {
        path.push_back(currentPath);
        return;
    }
    
    visited[x][y] = true;
    
    // Move down
    if (x + 1 < n && maze[x + 1][y] == 1 && !visited[x + 1][y])
        findPaths(maze, x + 1, y, visited, path, currentPath + " (" + to_string(x + 1) + "," + to_string(y) + ")");
    
    // Move right
    if (y + 1 < m && maze[x][y + 1] == 1 && !visited[x][y + 1])
        findPaths(maze, x, y + 1, visited, path, currentPath + " (" + to_string(x) + "," + to_string(y + 1) + ")");
    
    // Move up
    if (x - 1 >= 0 && maze[x - 1][y] == 1 && !visited[x - 1][y])
        findPaths(maze, x - 1, y, visited, path, currentPath + " (" + to_string(x - 1) + "," + to_string(y) + ")");
    
    // Move left
    if (y - 1 >= 0 && maze[x][y - 1] == 1 && !visited[x][y - 1])
        findPaths(maze, x, y - 1, visited, path, currentPath + " (" + to_string(x) + "," + to_string(y - 1) + ")");
    
    visited[x][y] = false;
}

int main() {
    int n, m;
    cout << "Enter the dimensions of the maze (n m): ";
    cin >> n >> m;
    
    vector<vector<int>> maze(n, vector<int>(m));
    cout << "Enter the maze (1 for open cell, 0 for blocked cell):" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> maze[i][j];
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<string> path;
    string currentPath = "(0,0)";
    
    if (maze[0][0] == 1 && maze[n - 1][m - 1] == 1)
        findPaths(maze, 0, 0, visited, path, currentPath);
    
    if (path.empty()) {
        cout << "No Path Exists" << endl;
    } else {
        cout << "All Paths:" << endl;
        for (const auto& p : path)
            cout << p << endl;
    }
    
    return 0;
}
