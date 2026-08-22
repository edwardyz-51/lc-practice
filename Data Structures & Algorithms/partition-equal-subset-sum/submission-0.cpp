class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // sum 0 is always possible (pick nothing)

        for (int x : nums) {
            // go backwards so each number is used at most once
            for (int s = target; s >= x; --s) {
                if (dp[s - x]) dp[s] = true;
            }
            if (dp[target]) return true; // early exit if we hit target
        }

        return dp[target];
    }
};