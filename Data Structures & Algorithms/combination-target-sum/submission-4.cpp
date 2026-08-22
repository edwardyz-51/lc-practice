class Solution {
private:
void dfs(vector<int>&sub,vector<vector<int>>&res,int target, int index, const vector<int>&nums) {
    if (index >= nums.size() || target < 0) return;
    
    if (target == 0) {
        res.push_back(sub);
        return;
    }
        sub.push_back(nums[index]);
        dfs(sub,res,target-nums[index],index,nums);
        sub.pop_back();
        dfs(sub,res,target,index+1,nums);

}
// nums = [2,5,6,9] 

//target = 9
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int index = 0;
        sort(nums.begin(),nums.end());
        vector<int> sub;
        vector<vector<int>>res;
        dfs(sub,res,target,0, nums);
        return res;
    }
};
