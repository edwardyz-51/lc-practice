class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // [1,1,2] size = 3
        vector<int>sub;
        vector<vector<int>>ans;
        dfs(sub,ans,0,nums);
        return ans;
    }

    void dfs(vector<int>&sub,vector<vector<int>>&ans,int index,const vector<int>&nums){
        if (index==nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[index]);
        dfs(sub,ans,index+1,nums);
        sub.pop_back();
        while (index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        dfs(sub,ans,index+1,nums);
    }
};
