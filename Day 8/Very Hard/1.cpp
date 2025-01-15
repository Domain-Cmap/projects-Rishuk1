#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);  // Graph represented as adjacency list
    for (const auto& time : times) {
        graph[time[0]].push_back({time[1], time[2]});
    }
    
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    int maxDist = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX) return -1;
        maxDist = max(maxDist, dist[i]);
    }
    return maxDist;
}

int main() {
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    int n = 4, k = 2;
    cout << networkDelayTime(times, n, k) << endl;  // Output: 2
    return 0;
}
