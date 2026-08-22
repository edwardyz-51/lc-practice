class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int total = 1;
        int nozero = 1;
        int zerocount=0;
        for (int i = 0; i <nums.size(); ++i) {
            total *=nums[i];
            if (nums[i]==0) {
                zerocount++;
                continue;
            }
            nozero*=nums[i];
        }
        if (zerocount>1){
            vector<int>zero(nums.size(),0);
            return zero;
        }
        for (int i = 0; i <nums.size(); ++i){
            if (nums[i]==0){
                ans[i]=nozero;
                continue;
            }
            ans[i] = (total / nums[i]);
        }
        return ans;
    }
};
