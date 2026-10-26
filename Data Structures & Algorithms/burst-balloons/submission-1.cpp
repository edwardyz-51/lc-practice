class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                for (int i = l; i <= r; i++) {
                    int left = (l == 0) ? 1 : nums[l - 1];
                    int right = (r == n - 1) ? 1 : nums[r + 1];

                    int coins = left * nums[i] * right;

                    if (i > l)
                        coins += dp[l][i - 1];

                    if (i < r)
                        coins += dp[i + 1][r];

                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return dp[0][n - 1];
    }
};