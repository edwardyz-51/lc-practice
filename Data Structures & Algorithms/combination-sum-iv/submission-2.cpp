class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0] = 1;

        for (int total = 1; total <= target; total++) {
            for (int num : nums) {
                if (total >= num) { 
                    //if total is less than num, then we go negative
                    dp[total] += dp[total - num];
                }
            }
        }
        return dp[target];
    }
};