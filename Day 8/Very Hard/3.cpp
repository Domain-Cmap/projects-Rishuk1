#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
    
private:
    vector<int> parent;
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind uf(n + 1);
    
    for (int i = n - 1; i >= 0; --i) {
        int u = edges[i][0], v = edges[i][1];
        if (uf.find(u) == uf.find(v)) {
            return edges[i];
        } else {
            uf.unionSets(u, v);
        }
    }
    
    return {};
}

int main() {
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result = findRedundantConnection(edges);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;  // Output: [2, 3]
    return 0;
}
