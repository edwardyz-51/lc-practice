class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        vector<int>squares;
        for (int k = 1; k * k <= n; ++k){
            squares.push_back(k*k);
        }
        dp[0]=0;
        for (int sum = 0; sum <= n; ++sum){
            for (int square : squares){
                if (square > sum || dp[sum-square]==INT_MAX) continue;
                dp[sum] = min(dp[sum-square]+1, dp[sum]);
            }
        }
        return dp[n];
    }
};