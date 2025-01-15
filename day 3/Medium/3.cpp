#include <vector>
#include <cstring>
#include <algorithm>

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = nums[i];
        }

        for (int start = n - 2; start >= 0; --start)
        {
            for (int end = start + 1; end < n; ++end)
            {

                dp[start][end] = std::max(nums[start] - dp[start + 1][end], nums[end] - dp[start][end - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};