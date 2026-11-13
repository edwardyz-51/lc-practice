class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        ranges::sort(nums);
        for (int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            ans+= upper_bound(nums.begin()+i+1,nums.end(),upper - num)-
                  lower_bound(nums.begin()+i+1,nums.end(),lower - num);
        }
        return ans;
    }
};
