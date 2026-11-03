class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        int ans = 0;    
        vector<vector<int>>dp(n,vector<int>(m,0));
        static constexpr int dir[5] = {0,1,0,-1,0};
        auto dfs = [&](this auto&dfs, int row, int col)->int{
            if (dp[row][col]) return dp[row][col];
            dp[row][col] = 1;
            for (int i = 0; i < 4; ++i){
                int nr = row + dir[i], nc = col + dir[i+1];
                if (nr < 0 || nc < 0 || nr == n || nc == m || matrix[nr][nc] <= matrix[row][col]) continue;
                dp[row][col]=max(dp[row][col],1+dfs(nr,nc));
            }
            return dp[row][col];

        };
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < m; ++col){
                if (dp[row][col]==0){
                    dfs(row,col);
                    ans = max(ans,dp[row][col]);
                } 
            }
        }
        return ans;
    }
};
