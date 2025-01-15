#include <iostream>
#include <vector>
using namespace std;

bool divisorGame(int n) {
    vector<bool> dp(n + 1, false);
    
    for (int i = 2; i <= n; ++i) {
        for (int x = 1; x < i; ++x) {
            if (i % x == 0 && !dp[i - x]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << (divisorGame(n) ? "Alice wins" : "Bob wins") << endl;
    return 0;
}
