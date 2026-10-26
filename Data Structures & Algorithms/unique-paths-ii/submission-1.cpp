class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.front().size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dp[0][0]= obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < m; ++col){
                if (obstacleGrid[row][col]==1)
                    dp[row][col] = 0;
                else {
                    if (!row && !col) continue;
                    int above = row > 0 ? dp[row-1][col] : 0;
                    int left = col > 0 ? dp[row][col-1] : 0;
                    dp[row][col] = above+left;
                }
                
            }
        }
        return dp[n-1][m-1];
    }
};