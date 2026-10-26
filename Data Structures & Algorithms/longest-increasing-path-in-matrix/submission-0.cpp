class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix.front().size();
        int ans = 0;
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        // dp[r][c] = longest path ending at (r,c)
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < m; ++col){
                if (dp[row][col]==0){
                    dp[row][col] = dfs(row,col,dp,matrix);
                    ans = max(ans,dp[row][col]);
                } 
            }
        }
        return ans;
    }

    int dfs(int row, int col, vector<vector<int>>&dp, const vector<vector<int>>& matrix){
        static int directions[] = {0,1,0,-1,0};
        if (dp[row][col]) return dp[row][col];
        int maxLen = dp[row][col];
        for (int i = 0; i < 4; ++i){
            int nr = row + directions[i], nc = col + directions[i+1];
            if (nr < 0 || nc < 0 
            || nr == matrix.size() || nc==matrix.front().size() 
            || matrix[nr][nc] >= matrix[row][col])continue;
            maxLen = max(maxLen,dfs(nr,nc,dp,matrix));
        }
        dp[row][col] = maxLen+1;
        return maxLen+1;

    }
};
