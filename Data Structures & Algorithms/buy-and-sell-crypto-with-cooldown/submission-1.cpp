class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int buying = 0; buying < 2; ++buying) {
                if (buying == 1) {
                    int buy = dp[i + 1][0] - prices[i]; //buy now
                    int cooldown = dp[i + 1][1]; //if bought previously
                    dp[i][1] = max(buy, cooldown);
                } else {
                    int sell = dp[min(i+2,n)][1] + prices[i];
                    int cooldown = dp[i + 1][0];
                    dp[i][0] = max(sell, cooldown);
                }
            }
        }

        return dp[0][1];
    }
};