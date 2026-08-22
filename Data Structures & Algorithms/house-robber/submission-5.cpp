class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> rob (n);
        if (n == 0) return 0;
        if (n==1) return max(nums[0],0); 
        rob[0]=nums[0]; 
        rob[1] = max(rob[0],nums[1]); 
        for (int i = 2; i< nums.size(); ++i) {
            rob[i] = rob[i-2]+nums[i]>rob[i-1] ? rob[i-2]+nums[i] : rob[i-1];
        }
        return rob[n-1];
    }
};
