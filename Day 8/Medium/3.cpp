#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
        return {0};
    }

    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    queue<int> leaves;
    vector<int> degree(n, 0);

    for (int i = 0; i < n; ++i) {
        degree[i] = graph[i].size();
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }

    int remainingNodes = n;
    while (remainingNodes > 2) {
        int leavesSize = leaves.size();
        remainingNodes -= leavesSize;

        for (int i = 0; i < leavesSize; ++i) {
            int leaf = leaves.front();
            leaves.pop();

            for (int neighbor : graph[leaf]) {
                if (--degree[neighbor] == 1) {
                    leaves.push(neighbor);
                }
            }
        }
    }

    vector<int> result;
    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }

    return result;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    
    vector<int> result = findMinHeightTrees(n, edges);
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
