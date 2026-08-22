class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>sub;
        dfs(sub,ans,0,target,nums);
        return ans;
    }
    void dfs(vector<int>&sub,vector<vector<int>>&ans, int index, int target,vector<int>&nums){
        if (index>=nums.size()|| target<0) return;
        if (target==0) {
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[index]);
        dfs(sub,ans,index,target-nums[index],nums);
        sub.pop_back();
        dfs(sub,ans,index+1,target,nums);
    }
};
