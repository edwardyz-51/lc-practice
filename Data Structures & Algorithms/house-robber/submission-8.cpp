class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n=nums.size();
        if (n==1) return nums[0];
        int prev2 = 0, prev1 = 0, cur;
        for (size_t i(0uz); i < n;++i){
            cur = max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;

    }
};
