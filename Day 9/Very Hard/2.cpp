#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int slidingPuzzle(vector<vector<int>>& board) {
    string target = "123450"; // target solved state
    string start = "";
    for (auto& row : board) {
        for (int num : row) {
            start += to_string(num);
        }
    }
    if (start == target) return 0;

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    unordered_map<string, int> visited;
    queue<string> q;
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        int zeroPos = curr.find('0');

        for (auto& dir : directions) {
            int row = zeroPos / 3 + dir.first;
            int col = zeroPos % 3 + dir.second;
            if (row >= 0 && row < 2 && col >= 0 && col < 3) {
                int newPos = row * 3 + col;
                string next = curr;
                swap(next[zeroPos], next[newPos]);
                if (!visited.count(next)) {
                    visited[next] = visited[curr] + 1;
                    if (next == target) return visited[next];
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    cout << "Minimum moves to solve: " << slidingPuzzle(board) << endl;
    return 0;
}
