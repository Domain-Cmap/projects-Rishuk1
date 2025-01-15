#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    vector<int> result;
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result = bfsTraversal(n, adj);
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
