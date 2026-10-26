class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minPrefix = 0, cur = 0, ans = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
            cur+=nums[i],
            ans = max({ans,cur,cur-minPrefix}),
            minPrefix=min(minPrefix,cur);
        
        return ans;
    }
};
