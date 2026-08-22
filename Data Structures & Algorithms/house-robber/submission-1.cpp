class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> rob (n);
        if (n == 0) return 0;
        if (n==1) return max(nums[0],0); // 1,2,3,1
        rob[0]=nums[0]; // if only house 1 exists, best is rob house 1.
        rob[1] = max(rob[0],nums[1]); //if house 1 and house 2 exist, rob the bigger one
        for (int i = 2; i< nums.size(); ++i) {
            rob[i] = max(rob[i-2]+nums[i],rob[i-1]);
        }
        return rob[n-1];
    }
};
