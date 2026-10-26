class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
        int suffixSum = nums[n-1];
        for (int i = n-2; i>=0; --i)
            suffixSum+=nums[i],
            suffix[i]=max(suffix[i+1],suffixSum);
        int maxSum = nums[0];
        int curMax = 0;
        int prefixSum = 0;
        for (size_t i(0uz); i < n; ++i){
            if (curMax < 0) curMax = 0;
            curMax += nums[i];
            maxSum = max(maxSum,curMax);
            prefixSum+=nums[i];
            if (i+1 < n)  maxSum = max(maxSum, prefixSum + suffix[i + 1]);
        }
        return maxSum;
    }
};