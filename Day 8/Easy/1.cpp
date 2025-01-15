#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int n, vector<vector<int>>& adjList, int source, int destination) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == destination) {
            return true;
        }

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> adjList(n);

    for (auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    return bfs(n, adjList, source, destination);
}

int main() {
    int n, source, destination, e;
    cout << "Enter the number of vertices (n): ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << "Enter the source and destination vertices: ";
    cin >> source >> destination;

    if (validPath(n, edges, source, destination)) {
        cout << "Yes, there is a path from source to destination." << endl;
    } else {
        cout << "No, there is no path from source to destination." << endl;
    }
    return 0;
}
