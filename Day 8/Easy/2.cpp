#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfsTraversal(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    vector<int> result;
    dfs(0, adj, visited, result);
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

    vector<int> result = dfsTraversal(n, adj);
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
