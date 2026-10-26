class Solution {
    const int MOD = 1e9+7;
public:
    int countVowelPermutation(int n) {
        long long ans = 0;
        vector<vector<long long>>dp(n+1,vector<long long>(5,-1));
        for (int i = 0; i < 5; ++i){
            ans = (ans + dfs(n, i, dp)) % MOD;
        }
        return ans % MOD;
    }

    long long dfs(int n, int c, vector<vector<long long>>&dp){
        if (n==1) return 1;
        if (dp[n][c] != -1) return dp[n][c];
        if (c == 0) { //0
            dp[n][c] = dfs(n-1,4,dp) + dfs(n-1,1,dp) + dfs(n-1,2,dp);
        } else if (c==1){ //1
            dp[n][c] = dfs(n-1,0,dp) + dfs(n-1,2,dp);
        } else if (c==2){ //2
            dp[n][c] = dfs(n-1,1,dp) + dfs(n-1,3,dp);
        } else if (c==3) {//3
            dp[n][c] = dfs(n-1,2,dp);
        } else if (c==4) {//4
            dp[n][c] = dfs(n-1,3,dp) + dfs(n-1,2,dp);
        }
        return dp[n][c]%=MOD;

    }
};


/*
case 1: last letter is 0
f(0) = 1;
f(n,0) = f(n-1,4) + f(n-1,1) + f(n-1,2)
case 2: last letter is 1
f(n,1) = f(n-1, 0) + f(n-1,2)
case 3: last letter is 2
f(n,2) = f(n-1,1) + f(n-1, 3)
case 4: last letter is 3
f(n,3) = f(n-1,2)
case 5: last letter is 4
f(n, 4) = f(n-1,3) + f(n-1,2)



*/
