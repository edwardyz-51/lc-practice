class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>subset;
        dfs(1,k,n,subset,ans);
        return ans;
    }

    void dfs(int num, int k, int n, vector<int>&subset, vector<vector<int>>&ans){
        if (num > n){
            if (subset.size()==k)ans.push_back(subset);
            return;
        } 
        subset.push_back(num);
        dfs(num+1,k,n,subset,ans);
        subset.pop_back();
        dfs(num+1,k,n,subset,ans);
        

    }
};