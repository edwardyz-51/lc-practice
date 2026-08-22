class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, cur = 0;
        for (int i : nums) {
            if (i>cur && cur<0)cur = i; //reset condition
            else cur+=i;
            if (cur>maxSum) maxSum=cur;       
        }
        return maxSum;

    }
};
