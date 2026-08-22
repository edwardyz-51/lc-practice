class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>sol;
        vector<int>subset;

        dfs(sol,subset,0,0,candidates,target);
        return sol;
    }

    void dfs(vector<vector<int>>&sol, vector<int>&subset, int total, int index, vector<int>&candidates, int target){
        if (total==target) {sol.push_back(subset); return;}
        if (total>target || index>=candidates.size()) return;

        subset.push_back(candidates[index]);
        dfs(sol,subset, total+candidates[index],index+1,candidates,target);
        while (index +1 <candidates.size() && candidates[index] == candidates[index+1]){
            index++;
        }
        subset.pop_back();
        dfs(sol,subset,total,index+1,candidates,target);
    }
};
