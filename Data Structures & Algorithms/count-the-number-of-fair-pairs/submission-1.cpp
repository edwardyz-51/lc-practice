class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        //for each index, check all indices greater than it.
        //so just need k + num >= lower && k+num <= upper
        //so all indices greater than i, between lower-num and upper - num
        ranges::sort(nums);
        for (int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            ans+= upper_bound(nums.begin()+i+1,nums.end(),upper - num)-
                  lower_bound(nums.begin()+i+1,nums.end(),lower - num);
        }
        return ans;
    }
};
