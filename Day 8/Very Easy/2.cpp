#include <iostream> 
#include <vector> 
using namespace std; 
 
int findJudge(int n, vector<vector<int>>& trust) { 
    vector<int> trustCount(n + 1, 0); 
 
    for (const auto& t : trust) { 
        trustCount[t[0]]--; 
        trustCount[t[1]]++; 
    } 
    for (int i = 1; i <= n; ++i) { 
        if (trustCount[i] == n - 1) { 
            return i; 
        } 
    } 
    return -1; 
} 
 
 
int main() { 
    int n, m; 
    cin >> n; 
    cin >> m; 
    vector<vector<int>> trust(m, vector<int>(2)); 
    for (int i = 0; i < m; ++i) { 
        cin >> trust[i][0] >> trust[i][1]; 
    } 
    int judge = findJudge(n, trust); 
    if (judge == -1) { 
        cout << "No town judge found." << endl; 
    } else { 
        cout << "The town judge is: " << judge << endl; 
    } 
    return 0; 
} 
