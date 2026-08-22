class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int total=1, nozero = 1,zerocount=0;
        for (int i = 0; i <nums.size(); ++i) {
            total *=nums[i];
            if (nums[i]==0) {
                if (zerocount==1) return vector<int>(nums.size(),0);   
                zerocount++;
                continue;
            }
            nozero*=nums[i];
        }
        
        for (int i = 0; i <nums.size(); ++i){
            ans[i] = nums[i]==0 ? nozero : (total/nums[i]);
        }
        return ans;
    }
};
