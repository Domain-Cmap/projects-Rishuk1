#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;

    for (int i = 0; i < n; ++i) {
        if (!dp[i]) continue;
        for (int j = 1; j <= nums[i] && i + j < n; ++j) {
            dp[i + j] = true;
        }
    }

    return dp[n - 1];
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << (canJump(nums) ? "true" : "false") << endl;
    return 0;
}
