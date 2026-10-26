class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long ans = 0;
        size_t n = points.size(), m = points.front().size();
        
        vector<vector<long long>>dp(n,vector<long long>(m,0));
        dp[0][0] = points[0][0];
        dp[0] = vector<long long>(points[0].begin(), points[0].end());
        for (size_t row(1uz); row < n; ++row){
            for (size_t col(0uz); col < m; ++col){
                int cur = points[row][col];
                for (size_t prev(0uz); prev < m; ++prev){
                    long long cost = abs((int)(col)-(int)(prev));
                    dp[row][col] = max(dp[row][col],cur + dp[row-1][prev] - cost);
                }
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};