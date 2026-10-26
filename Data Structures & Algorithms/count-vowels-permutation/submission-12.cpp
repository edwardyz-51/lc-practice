class Solution {
    const int MOD = 1e9+7;
public:
    int countVowelPermutation(int n) {
        long long ans = 0;
        vector<vector<long long>>dp(n+1,vector<long long>(5,-1));
        for (int i = 0; i < 5; ++i)
            ans = (ans + dfs(n, i, dp)) % MOD;
        return ans % MOD;
    }
    long long dfs(int n, int c, vector<vector<long long>>&dp){
        if (n==1) return 1;
        if (dp[n][c] != -1) return dp[n][c];
        switch (c){
            case 0:
                dp[n][c] = dfs(n-1,4,dp) + dfs(n-1,1,dp) + dfs(n-1,2,dp);
                break;
            case 1:
                dp[n][c] = dfs(n-1,0,dp) + dfs(n-1,2,dp);
                break;
            case 2:
                dp[n][c] = dfs(n-1,1,dp) + dfs(n-1,3,dp);
                break;
            case 3:
                dp[n][c] = dfs(n-1,2,dp);
                break;
            case 4:
                dp[n][c] = dfs(n-1,3,dp) + dfs(n-1,2,dp);
                break;
        }
        return dp[n][c]%=MOD;
    }
};

