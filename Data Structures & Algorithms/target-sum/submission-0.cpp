class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> next;
            for (auto [sum, count] : dp) {
                next[sum + num] += count;
                next[sum - num] += count;
            }
            dp = move(next);
        }

        return dp[target];
    }
};