class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(5, 1);

        for (int i = 2; i <= n; ++i) {
            vector<long long> next(5);

            next[0] = (dp[4] + dp[1] + dp[2]) % MOD;
            next[1] = (dp[0] + dp[2]) % MOD;
            next[2] = (dp[1] + dp[3]) % MOD;
            next[3] = dp[2];
            next[4] = (dp[3] + dp[2]) % MOD;

            dp = next;
        }

        long long ans = 0;
        for (long long x : dp)
            ans = (ans + x) % MOD;

        return ans;
    }
};