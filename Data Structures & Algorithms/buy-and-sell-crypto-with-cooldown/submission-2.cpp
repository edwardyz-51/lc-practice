class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(N, vector<int>(2, -1));

        auto dfs = [&](this auto& dfs, int day, int hasStock) -> int {
            if (day >= N) return 0;

            if (dp[day][hasStock] != -1)
                return dp[day][hasStock];

            int skip = dfs(day + 1, hasStock);

            if (hasStock) {
                int sell = prices[day] + dfs(day + 2, 0);
                return dp[day][hasStock] = max(skip, sell);
            }

            int buy = dfs(day + 1, 1)-prices[day];
            return dp[day][hasStock] = max(skip, buy);
        };

        return dfs(0, 0);
    }
};