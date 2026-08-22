class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        return max(houseRobber(nums,0,nums.size()-2),houseRobber(nums,1,nums.size()-1));
    }

    int houseRobber(const vector<int>&nums, int start, int end){
        int prev2 = nums[start];
        int prev1 = max(nums[start],nums[start+1]);
        int cur;
        for (int i = start+2; i <= end; ++i){
            cur = max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};
