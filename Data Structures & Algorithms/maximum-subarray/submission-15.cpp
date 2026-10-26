class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minPrefix = 0, cur = 0, ans = INT_MIN;
        for (size_t i(0uz); i < nums.size(); ++i){
            cur+=nums[i];
            ans = max({ans,cur-minPrefix});
            if (cur<0) minPrefix= min(minPrefix,cur);
        }
        return ans;
    }
};
