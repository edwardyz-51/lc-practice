class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp (n+1,0);
        dp[1]=1;
        for (int num = 2; num <=n; ++num){
            if (num!=n) dp[num]=num;
            for (int i = 0; i < num; ++i){
                dp[num] = max(dp[num],dp[i]*dp[num-i]);
            }
        }

        return dp[n];
    }
};