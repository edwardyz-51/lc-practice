class Solution {

public:
    vector<vector<int>> solution;
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;

        vector<int>subset;
        backtracking(0,nums,subset);
        return solution;
    }

    void backtracking(int index, vector<int> &nums, vector<int> &subset) {
        if (index == nums.size()) solution.push_back(subset);
        if (index < nums.size()) {
            subset.push_back(nums[index]);
            backtracking(index+1, nums, subset);
            subset.pop_back();
        }
        if (index < nums.size()) {
            backtracking(index+1, nums, subset);
        }
        
    }


};
