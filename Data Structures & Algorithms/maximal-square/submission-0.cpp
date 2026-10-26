class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        size_t n = matrix.size(), m = matrix.front().size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans = 0;
        for (size_t row(0uz); row < n; ++row){
            for (size_t col(0uz); col < m; ++col){
                if (matrix[row][col]=='0') continue;
                if (row == 0 || col == 0) {
                        dp[row][col] = 1;
                } else {
                    dp[row][col] = 1 + min({dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]});
                }
                ans = max(ans, dp[row][col]);
            }
        }
        return ans * ans;
    }
};