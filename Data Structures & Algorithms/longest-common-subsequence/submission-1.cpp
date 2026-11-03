class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size(), M = text2.size();
        vector<vector<int>>dp(N+1,vector<int>(M+1,-1));
        auto dfs = [&](this auto& dfs, int i, int j)->int{
            if (i==N || j==M) return 0;
            if (dp[i][j]!=-1) return dp[i][j];
            if (text1[i]==text2[j]) return dp[i][j] = 1+dfs(i+1,j+1);
            else return dp[i][j] = max(dfs(i+1,j),dfs(i,j+1));
        };
        return dfs(0,0);
    }
};
