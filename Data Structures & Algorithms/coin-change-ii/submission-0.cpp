class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int coin = coins[i - 1];
            dp[i][0] = 1;  
            for (int a = 1; a <= amount; a++) {
                dp[i][a] = dp[i - 1][a];  
                if (a >= coin) 
                    dp[i][a] += dp[i][a - coin];  
            }
        }
        return dp[n][amount];
    }
};