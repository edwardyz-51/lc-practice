class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int cur = 0;
        for (int i : nums) {
            if (i>cur && cur<0){ //reset
                cur = i; //cur = 1, nums[i] = 20
            } else { //
                cur+=i;
            }
            if (cur>maxSum) maxSum=cur;       
        }
        return maxSum;

    }
};
