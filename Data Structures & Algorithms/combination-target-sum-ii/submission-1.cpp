class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        ranges::sort(nums);
        vector<vector<int>>ans;
        vector<int>subset;
        auto dfs = [&](this auto& self, int i, int sum)->void{
            if (sum==target) {
                ans.push_back(subset);
                return;
            }
            if (i == nums.size() || sum>target) return;
            subset.push_back(nums[i]);
            
            self(i+1,sum+nums[i]);
            subset.pop_back();
            while (i + 1 < nums.size() && nums[i]==nums[i+1]) ++i;
            self(i+1,sum);
        };
        dfs(0,0);
        return ans;
    }
};
