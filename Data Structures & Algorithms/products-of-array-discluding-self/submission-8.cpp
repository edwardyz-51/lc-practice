class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero = 0;
        for (int i : nums){
            if (i==0){
                zero++;
                continue;
            } 
            product*=i;
        } 
        if (zero>1) return vector<int>(nums.size(),0);
        vector<int>ans(nums.size());
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i]==0) ans[i]=product;
            else ans[i]= zero ? 0 : product/nums[i];
        }
        return ans;
    }
};
