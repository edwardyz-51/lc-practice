class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int>mem(nums.size(),1);
        for (int idx = 1; idx < nums.size(); ++idx){
            for (int j = 0; j < idx; ++j){
                if (nums[idx] > nums[j]) mem[idx] = max(mem[idx],mem[j]+1);
                ans = max(ans,mem[idx]);
            }
        }
        return ans;
    }
};
