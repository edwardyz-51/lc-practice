class Solution {
    const int A = 0;
    const int E = 1;
    const int I = 2;
    const int O = 3;
    const int U = 4;
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
        if (c == A) { //a
            dp[n][c] = dfs(n-1,U,dp) + dfs(n-1,E,dp) + dfs(n-1,I,dp);
        } else if (c==E){ //e
            dp[n][c] = dfs(n-1,A,dp) + dfs(n-1,I,dp);
        } else if (c==I){ //i
            dp[n][c] = dfs(n-1,E,dp) + dfs(n-1,O,dp);
        } else if (c==O) {//o
            dp[n][c] = dfs(n-1,I,dp);
        } else if (c==U) {//u
            dp[n][c] = dfs(n-1,O,dp) + dfs(n-1,I,dp);
        }
        return dp[n][c]%=MOD;

    }
};


/*
case 1: last letter is a
f(0) = 1;
f(n,a) = f(n-1,u) + f(n-1,e) + f(n-1,i)
case 2: last letter is e
f(n,e) = f(n-1, a) + f(n-1,i)
case 3: last letter is i
f(n,i) = f(n-1,e) + f(n-1, o)
case 4: last letter is o
f(n,o) = f(n-1,i)
case 5: last letter is u
f(n, u) = f(n-1,o) + f(n-1,i)



*/
