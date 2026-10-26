class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size(); 
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        dp[0][0] = grid[0][0];
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < m; ++col){
                if (!row && !col) continue;
                int best = 0;
                if (row == 0) best = dp[row][col-1];
                else if (col==0) best = dp[row-1][col];
                else best = min(dp[row][col-1], dp[row-1][col]);
                dp[row][col] = best + grid[row][col];
            }
        }  
        return dp[n-1][m-1];
    }
};