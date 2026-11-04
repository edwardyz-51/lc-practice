class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        auto dfs = [&](this auto&self, int i)->void{
            if (i == nums.size()){
                ans.push_back(subset);
                return;
            }
            subset.push_back(nums[i]);
            self(i+1);
            subset.pop_back();
            self(i+1);

        };
        dfs(0);
        return ans;
    }
};
