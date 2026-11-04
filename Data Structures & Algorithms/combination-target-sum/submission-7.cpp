class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        auto dfs = [&](this auto& self, int i, int sum)->void{
            if (i == nums.size() || sum>target) return;
            if (sum==target) {
                ans.push_back(subset);
                return;
            }
            subset.push_back(nums[i]);
            self(i,sum+nums[i]);
            subset.pop_back();
            // while (i + 1 < nums.size() && nums[i]==nums[i+1]) ++i;
            self(i+1,sum);
        };
        dfs(0,0);
        return ans;
    }
};
