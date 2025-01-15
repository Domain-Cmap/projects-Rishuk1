#include <iostream>
#include <vector> 
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i >> 1] + (i & 1);  // Shift i to the right and add the least significant bit
    }
    return dp;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = countBits(n);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
