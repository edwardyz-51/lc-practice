class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag = nums.size()-1;
        for (int i = nums.size()-2;i>=0;--i){
            if (i+nums[i]>=flag) flag = i;
        }
        return flag==0;
    }
};
