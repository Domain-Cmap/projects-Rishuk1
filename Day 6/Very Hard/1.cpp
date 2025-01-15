#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
    int countPalindromicPaths(int n, vector<int>& parent, string& s) {
        unordered_map<int, int> freqMap; // Keeps track of frequency of bitmask
        freqMap[0] = 1; // Initialize the root bitmask
        
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; ++i) {
            tree[parent[i]].push_back(i);
        }
        
        int result = 0;
        dfs(0, tree, s, 0, freqMap, result);
        return result;
    }

    void dfs(int node, vector<vector<int>>& tree, string& s, int mask, unordered_map<int, int>& freqMap, int& result) {
        // Update mask for current node
        mask ^= (1 << (s[node] - 'a')); 
        
        // Count the current path that can form a palindrome
        result += freqMap[mask]; 
        
        // Count paths that can form a palindrome by flipping one character (for odd-length palindromes)
        for (int i = 0; i < 26; ++i) {
            result += freqMap[mask ^ (1 << i)];
        }
        
        // Update the frequency map
        freqMap[mask]++;
        
        // Traverse all children of the current node
        for (int child : tree[node]) {
            dfs(child, tree, s, mask, freqMap, result);
        }
        
        // After DFS, remove this node from the map
        freqMap[mask]--;
    }
};

int main() {
    Solution sol;
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "acaabc";
    cout << sol.countPalindromicPaths(6, parent, s) << endl; // Output: 8
    return 0;
}
