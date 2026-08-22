class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col){
                if (row) dp[row][col]+=dp[row-1][col];
                if (col) dp[row][col]+=dp[row][col-1];
            }
        }
        return dp[m-1][n-1];
    }
};
