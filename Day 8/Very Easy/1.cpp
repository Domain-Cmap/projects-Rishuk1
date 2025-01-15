#include <iostream> 
#include <vector> 
using namespace std; 
 
int findCenter(vector<vector<int>>& edges) { 
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) { 
        return edges[0][0]; 
    } 
    return edges[0][1]; 
} 
int main() { 
    int n; 
    cout << "Enter the number of edges: "; 
    cin >> n; 
 
    vector<vector<int>> edges(n, vector<int>(2)); 
    cout << "Enter the edges:" << endl; 
    for (int i = 0; i < n; ++i) { 
        cin >> edges[i][0] >> edges[i][1]; 
    } 
 
    int center = findCenter(edges); 
 
    cout << "The center of the star graph is: " << center << endl; 
 
    return 0; 
} 
