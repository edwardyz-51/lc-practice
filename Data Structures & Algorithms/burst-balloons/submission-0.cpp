class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // len = size of interval [l, r]
        for (int len = 1; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;

                // i is the last balloon popped in [l, r]
                for (int i = l; i <= r; i++) {
                    int coins =
                        newNums[l - 1] * newNums[i] * newNums[r + 1];

                    coins += dp[l][i - 1] + dp[i + 1][r];

                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return dp[1][n];
    }
};