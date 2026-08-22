class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> rob (n); //best possible money from houses 0,..,i (i<n). TRUST BRO
        if (n == 0) return 0;
        if (n==1) return nums[0]; // 1,2,3,1
        rob[0]=nums[0]; // if only house 1 exists, best is rob house 1.
        rob[1] = max(rob[0],nums[1]); //if house 1 and house 2 exist, rob the bigger one
        for (int i = 2; i< nums.size(); ++i) { //if house 1, .., i exists, rob the maximum between dp(i-2) + house i or dp(i-1)
        //so either skip house i (if skipping it gives more than not)

            rob[i] = max(rob[i-2]+nums[i],rob[i-1]); 
        }
        return rob[n-1];
    }
};
