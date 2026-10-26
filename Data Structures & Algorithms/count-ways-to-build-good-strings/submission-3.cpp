class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9+7;
        vector<long long>dp(high+1,0);
        for (int length = 0; length <= high; ++length){
            long long add_zero = length-zero < 0 ? 0 :(dp[length-zero] + 1 %MOD);
            long long add_one = length-one < 0 ? 0 : (dp[length-one] + 1 %MOD);
            dp[length] = (add_zero + add_one) %MOD;
        }
        return ((dp[high]%MOD)-(dp[low-1]%MOD))%MOD;
    }
};
