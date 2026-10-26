class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9+7;
        vector<long long>dp(high+1,0);
        for (int length = 0; length <= high; ++length){
            dp[length] = 
            (length-zero < 0 ? 0 : (dp[length-zero] + 1 %MOD)) + 
            (length-one < 0 ? 0 : (dp[length-one] + 1 %MOD))%MOD;
        }
        return ((dp[high]%MOD)-(dp[low-1]%MOD));
    }
};
