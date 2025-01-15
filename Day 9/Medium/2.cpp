#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (const string& p1 : dp[j]) {
                for (const string& p2 : dp[i - j - 1]) {
                    dp[i].push_back("(" + p1 + ")" + p2);
                }
            }
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<string> result = generateParenthesis(n);
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
