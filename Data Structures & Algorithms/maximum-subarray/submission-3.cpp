class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int cur = 0;
        for (int i=0; i<nums.size();++i) {
            if (nums[i]>cur && cur<0){ //reset
                cur = nums[i]; //cur = 1, nums[i] = 20
            } else { //
                cur+=nums[i];
            }
            if (cur>maxSum) maxSum=cur;       
        }
        return maxSum;

    }
};
