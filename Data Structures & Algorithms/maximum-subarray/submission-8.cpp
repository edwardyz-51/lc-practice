class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minPrefix = nums[0], cur = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            cur+=nums[i];
            ans = max (ans, max (cur,cur-minPrefix));
            minPrefix=min(minPrefix,cur);
        }
        return ans;
    }
};
